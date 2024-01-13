#ifndef SALESPERSON_H
#define SALESPERSON_H

#include "User.h"

class Salesperson : public User {
public:
    Salesperson(const std::string& username, const std::string& password, const std::string& firstName,
                const std::string& lastName, const std::string& mobileNumber);

    void displayProfile() const override;
};

#endif
