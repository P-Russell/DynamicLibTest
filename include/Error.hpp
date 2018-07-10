#ifndef ERROR_HPP
#define ERROR_HPP

#include <stdexcept>
#include <string>

class Error
{
  public:
    class InitError : public std::exception
    {
      public:
        InitError() : std::exception()
        {
            this->_msg = "";
        }
        InitError(std::string const &str) : std::exception()
        {
            this->_msg = str;
        }
        virtual const char *what() const noexcept
        {
            if (this->_msg.size() > 0)
                return this->_msg.c_str();
            return "Error Initialising library";
        }

      private:
        std::string _msg;
    };

    class CreateWindowError : public std::exception
    {
      public:
        CreateWindowError(std::string const &str) : std::exception()
        {
            this->_msg = str;
        }
        CreateWindowError() : std::exception()
        {
            this->_msg = "";
        }

        virtual const char *what() const noexcept
        {
            if (this->_msg.size() > 0)
                return this->_msg.c_str();
            return "Error creating window";
        }

      private:
        std::string _msg;
    };

    class WindowMaxSizeError : public std::exception
    {
      public:
        WindowMaxSizeError(std::string const &str) : std::exception()
        {
            this->_msg = str;
        }
        WindowMaxSizeError() : std::exception()
        {
            this->_msg = "";
        }

        virtual const char *what() const noexcept
        {
            if (this->_msg.size() > 0)
                return this->_msg.c_str();
            return "Parameters execeeds max allowed values";
        }

      private:
        std::string _msg;
    };

    class WindowMinSizeError : public std::exception
    {
      public:
        WindowMinSizeError(std::string const &str) : std::exception()
        {
            this->_msg = str;
        }
        WindowMinSizeError() : std::exception()
        {
            this->_msg = "";
        }

        virtual const char *what() const noexcept
        {
            if (this->_msg.size() > 0)
                return this->_msg.c_str();
            return "Parameters is less than min allowed values";
        }

      private:
        std::string _msg;
    };
};

#endif