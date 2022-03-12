#include "ISubject.h"
#include <iostream>
#include <list>

class Subject : public ISubject {

    private:
        std::list<IObserver *> list_observer_;
        std::string message_;

    public:
        virtual ~Subject(){
            std::cout<<"Goodbye, I was the subject";
        }
        void Attach(IObserver * observer) override;
        void Detach(IObserver * observer) override;
        void Notify() override;
        void CreateMessage(std::string message="Empty");
        void HowManyObserver();
        void SomeBusinessLogic();

};

void Subject::Attach(IObserver * observer) {
    list_observer_.push_back(observer);
}

void Subject::Detach(IObserver * observer) {
    list_observer_.remove(observer);
}

void Subject::Notify() {
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();

    while (iterator!=list_observer_.end())
    {
        (*iterator)->Update(message_);
        ++iterator;
    }
    
}

void Subject::CreateMessage(std::string message) {
    this->message_ = message;
    Notify();
}

void Subject::HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " Observers";
}


void Subject::SomeBusinessLogic() {
    this->message_ = " change message message";
    Notify();
    std::cout<< "I'm about to do something important";
}






