#pragma once

#include "Resource.hpp"
class ResourceManager
{

    private:
        Resource* wsk;

    public:
        ResourceManager(){
            this->wsk= new Resource{};
        }

        ResourceManager(ResourceManager &w){
            this->wsk= new Resource{*w.getResource()};
        }

        ~ResourceManager(){
            delete wsk;
        }

        ResourceManager& operator=( ResourceManager &w){
            if (this == &w) {
                return *this;
            }
            delete resource;
            this->resource = new Resource{*w.getResource()};

            return *this;
        }

        double get(){return wsk->get();}

        Resource* getResource(){return wsk;}
};
