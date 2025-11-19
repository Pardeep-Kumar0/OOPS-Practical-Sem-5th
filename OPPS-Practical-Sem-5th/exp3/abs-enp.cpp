// Question (brief):
// Design a BankAccount class that encapsulates account data (account number, owner, balance). 
// Provide methods to deposit, withdraw (reject if insufficient funds), transfer to another account, 
// and safe accessors. Demonstrate usage and error handling.

// bank_account.cpp
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>

class BankAccount {
private:
    long accountNumber;
    std::string ownerName;
    double balance; // invariant: balance >= 0

    void ensure_positive(double amt) const {
        if (amt <= 0) throw std::invalid_argument("Amount must be > 0");
    }

public:
    BankAccount(long acc, const std::string &name, double init = 0.0)
        : accountNumber(acc), ownerName(name), balance(init)
    {
        if (init < 0) throw std::invalid_argument("Initial balance cannot be negative");
    }

    void deposit(double amt) {
        ensure_positive(amt);
        balance += amt;
    }

    void withdraw(double amt) {
        ensure_positive(amt);
        if (amt > balance) throw std::runtime_error("Insufficient funds");
        balance -= amt;
    }

    bool transfer(BankAccount &to, double amt) {
        try {
            // withdraw will validate amount and funds
            withdraw(amt);
            to.deposit(amt);
            return true;
        } catch (...) {
            return false; // transfer failed (invalid amount or insufficient funds)
        }
    }

    double getBalance() const { return balance; }
    long getAccountNumber() const { return accountNumber; }
    const std::string& getOwnerName() const { return ownerName; }

    void print() const {
        std::cout << accountNumber << " | " << std::setw(12) << ownerName
                  << " | Balance: " << std::fixed << std::setprecision(2) << balance << '\n';
    }
};

int main() {
    try {
        BankAccount a1(1001, "Saksham", 500.0);
        BankAccount a2(1002, "Bob", 100.0);

        a1.deposit(250.0);
        a1.withdraw(100.0);

        if (!a1.transfer(a2, 700.0)) // will fail: insufficient funds
            std::cout << "Transfer 700 failed as expected\n";

        if (a1.transfer(a2, 550.0)) // success: 500+250-100 = 650 -> transfer 550 leaves 100
            std::cout << "Transfer 550 succeeded\n";

        a1.print();
        a2.print();

        // demonstrate exception on bad input
        // a2.withdraw(-50); // uncomment to see invalid_argument thrown

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}


/* 
Explanation — concept & foundation (detailed but short)

1. Encapsulation (what & why)
We keep accountNumber, ownerName, and balance private. External code cannot change these members arbitrarily — it must use public methods 
(deposit, withdraw, transfer, accessors). This protects the invariant balance >= 0 and keeps internal representation flexible 
(you can later change balance to use cents as integer without changing callers).

2. Invariants & validation
ensure_positive checks amounts are > 0. Constructor prevents negative initial balance. withdraw checks both validity and sufficient funds. 
These checks ensure object never reaches an invalid state.

3. Methods vs direct data access
Methods encapsulate behavior: transfer composes withdraw and deposit. Because withdraw throws on errors, transfer catches exceptions and 
returns false on failure — this demonstrates error handling strategies: you can propagate exceptions or convert to status returns.

4. Exception safety
withdraw throws runtime_error for insufficient funds; deposit throws invalid_argument for non-positive amount. Exceptions keep error handling explicit. 
In transfer, we do a withdraw first, then deposit; if withdraw succeeds and deposit throws (rare here),
 the money is already withdrawn — for stronger safety you'd use a two-phase commit or roll-back. For this simple example, deposit cannot fail after validation.

5. const correctness
Accessors like getBalance() and print() are const; they promise not to modify object state — helpful for reasoning and compiler checks.

6. Clear responsibilities
BankAccount solely manages account data and operations. Code that uses it (like main) focuses on scenarios and testing, not internal bookkeeping.

7. Small & testable
Each method is small and testable. You can write unit tests for deposit, withdraw (normal and failure cases), transfer, and constructor validation.
*/
