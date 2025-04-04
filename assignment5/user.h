/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

 #ifndef USER_H
 #define USER_H
 
 #include <iostream>
 #include <string>
 
 class User {
 public:
   User(const std::string& name);
   ~User(); // Destructor
 
   // Copy constructor
   User(const User& user);
 
   // Copy assignment operator
   User& operator=(const User& user);
 
   // Delete move constructor
   User(User&& user) = delete;
 
   // Delete move assignment operator
   User& operator=(User&& user) = delete;
 
   void add_friend(const std::string& name);
   std::string get_name() const;
   size_t size() const;
   void set_friend(size_t index, const std::string& name);
 
   // Overloaded operators
   friend std::ostream& operator<<(std::ostream& os, const User& user);
   User& operator+=(User& rhs);
   bool operator<(const User& rhs) const;
 
 private:
   std::string _name;
   std::string* _friends;
   size_t _size;
   size_t _capacity;
 };
 
 #endif // USER_H
 

