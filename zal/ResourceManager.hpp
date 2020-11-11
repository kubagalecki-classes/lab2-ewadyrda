#pragma once

#include "Resource.hpp"
class ResourceManager{
    
    private:
        Resource* wsk;
    
    public:
        ResourceManager(){this->wsk = new Resource{};}
        
        ~ResourceManager(){delete wsk;}
    
        ResourceManager(ResourceManager &r){this->resource = new Resource{*r.getResource()};}
    
        ResourceManager& operator=( ResourceManager &r){
            if (this == &r) {
                return *this;
            }
            delete wsk;
            this->wsk = new Resource{*r.getResource()};
            return *this;
        }
    
        double get(){return resource->get();}
    
        Resource* getResource(){return wsk;}
};
