#ifndef TASK_1_EXCEPTIONTHROW_H
#define TASK_1_EXCEPTIONTHROW_H

#include <exception>
#include <string>
using namespace std;

class ExceptionThrow : public std::exception {
private:
    std::string errorMessage;

public:
    ExceptionThrow(std::string errorMessage) {
        this->errorMessage = errorMessage;
    }

    //для получение строки ошибки
    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};


#endif //TASK_1_EXCEPTIONTHROW_H
