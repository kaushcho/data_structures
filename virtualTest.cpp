#include <iostream>
#include <vector>
 
class Animal {
    public:
        virtual void eat() const { 
            std::cout << "I eat like a generic Animal." << std::endl; 
        }
        virtual ~Animal() { 
        }
};
 
class Wolf : public Animal {
    public:
        void eat() const { 
            std::cout << "I eat like a wolf!" << std::endl; 
        }
        virtual ~Wolf() { 
        }
};
 
class Fish : public Animal {
    public:
        void eat() const { 
            std::cout << "I eat like a fish!" << std::endl; 
        }
        virtual ~Fish() { 
        }
};
 
class GoldFish : public Fish {
    public:
        void eat() const { 
            std::cout << "I eat like a goldfish!" << std::endl; 
        }
        virtual ~GoldFish() { 
        }
};
 
class OtherAnimal : public Animal {
        virtual ~OtherAnimal() { 
        }
};
 
int main() {
    std::vector<Animal*> animals;
    animals.push_back(new Animal());
    animals.push_back(new Wolf());
    animals.push_back(new Fish());
    animals.push_back(new GoldFish());
    animals.push_back(new OtherAnimal());
 
    for (std::vector<Animal*>::const_iterator it = animals.begin(); it != animals.end(); ++it) {
        (*it)->eat();
        delete *it;
    }
 
    return 0;
}
