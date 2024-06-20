#include "user.h"

User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {
    // Initialize other user information fields if needed
}

bool User::authenticate(const std::string& password) const {
    // Compare hashed password with input password
    return this->password == password;
}
