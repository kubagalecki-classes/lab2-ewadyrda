#pragma once

#include "Resource.hpp"
class ResourceManager
{
   private:

       Resource* wsk=nullptr;

    public:

        ResourceManager(){wsk=new Resource;}

        ~ResourceManager(){delete wsk;}

        ResourceManager(const ResourceManager& e){
	          wsk=new Resource{*e.wsk};
	          }

         ResourceManager(ResourceManager&& e){
            wsk=move(e.wsk);
            e.wsk=nullptr;
            }

        ResourceManager& operator=(const ResourceManager& e){
            if(!(wsk==nullptr)){
                delete wsk;
            }
		          wsk=new Resource{*e.wsk};
		          delete *this;
        }

        ResourceManager& operator=(const ResourceManager&& e){
            if(&prze==this){
                return *this;
            }
		        else if(!(wsk==nullptr){
              delete wsk;
		        }
            wsk=move(e.wsk);
            e.wsk=nullptr;
            return *this;
        }

        double get() {return wsk->get();}

};
