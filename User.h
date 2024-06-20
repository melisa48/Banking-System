#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string username;
    std::string password; // Hashed password
    // Add other user information fields

public:
    User(const std::string& username, const std::string& password);
    // Add getters and setters for user information
    bool authenticate(const std::string& password) const;
};

#endif
