#pragma once

#include "include/Resource.hpp"

class ResourceManager{
    
        private:
    
            Resource* wsk;
    
        public:
    
            ResourceManager()
            {
                 this->wsk = new Resource{};
            }
    
            ResourceManager(ResourceManager &w)
            {
                this->wsk = new Resource{*w.getResource()};
            }
    
            ResourceManager(ResourceManager &&w)
            {
                this->wsk = w.getResource();
                w.wsk = nullptr;
            }
    
            ~ResourceManager(){delete wsk;}
    
            ResourceManager& operator=( ResourceManager &w)
            {
                if (this == &w) {
                    return *this;
                }
                
                delete wsk;
                this->wsk = new Resource{*w.getResource()};

                 return *this;
            }
    
            ResourceManager& operator=( ResourceManager &&w)
            {
                if (this == &w) {
                    return *this;
                 }
        
                delete wsk;
                this->wsk = w.getResource();
        
                w.wsk = nullptr;

                return *this;
           }
    
            double get(){
                return wsk->get();
            }
    
            Resource* getResource(){
                return wsk;
            }
};

