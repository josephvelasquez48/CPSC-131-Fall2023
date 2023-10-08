#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
template <typename T> class Item{
    
    public:
        T name;
        T expiration;
        T category;
        int quantity;
        
        Item(T n, T e, T c, int q){
           this->name = n;
           this->expiration = e;
           this->category = c;
           this->quantity = q;
        }
        
  T getname() const { return name; }
  T getexpiration() const { return expiration; }
  T getcategory() const { return category; }
  int getquantity(){ return quantity; }
};

template<typename T> class Inventory{
    
    std::vector<Item<T> > items;    
       
   
    public:
        void searchItem(T n){
            for (int i = 0; i < items.size(); i++) {
            if (items[i].name == n) {
                
                return;
            }
          }
            std::cout << "Item ("<<n<<") not found in inventory during search" << std::endl;
        }
        
        void Total(){
            int n=0;
           for(int i=0; i<items.size();i++){
               n+=items[i].quantity;
               
            } 
           std::cout<<"The total amount of items in the pantry are "<<n<<std::endl;
           std::cout<<std::endl;
        }
        
        void removeItem(T n){
            for (int i = 0; i < items.size(); i++) {
            if (items[i].name == n) {
                items[i].quantity=items[i].quantity-1;
                return;
            }
          }
            std::cout << "Item ("<<n<<") cannot be removed not found in inventory" << std::endl;
            std::cout<<std::endl;
        }
        
       void increaseQuantity(T n,int q){
          for (int i = 0; i < items.size(); i++) {
            if (items[i].name == n) {
                items[i].quantity=q;
                return;
            }
          }
        } 
        
       void updateItem(T n, T e, T c, int q ){
        for (int i = 0; i < items.size(); i++) {
            if (items[i].name == n) {
                items[i].name = n;
                items[i].expiration = e;
                items[i].category = c;
                items[i].quantity = q;
            return;
    }
  }
                // Item not found in inventory
        std::cout << "Item ("<<n<<") not found in inventory cant update" << std::endl;
           
        }
       
        void addNewItem(Item<T>& obj){
            
            items.push_back(obj);
           
           
          
        }
       
        void displayItems(){
            std::cout<<"-------Inventory-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw(15)<<"Quantity"<<std::setw(10)<<"Category"<<std::endl;
            for(int i=0; i<items.size();i++){
                std::cout<<std::left << std::setw(20)<<items[i].getname()<<std::setw(15)<<items[i].getexpiration()<<std::setw(15)<<items[i].getquantity()<<std::setw(15)<<items[i].getcategory()<<std::endl;
            }
            std::cout<<std::endl;
        }  
        
        
};


template<typename T>class Appointment{
    public:
        T c_name;
        T ap_date;
        T ap_time;
        T CWID;
        Appointment(T n, T d, T t, T cw){
            c_name = n;
            ap_date = d;
            ap_time = t;
            CWID = cw;
        }
        T getc_name() const { return c_name; }
        T getap_date() const { return ap_date; }
        T getap_time() const { return ap_time; }
        T getCWID(){ return CWID; }
};
template<typename T>class AppointmentSystem{
    
    std::vector<Appointment<T> > ap;
    public:
        void schedule(Appointment<T>& obj){
        ap.push_back(obj);
        }
        
        void display(){
            std::cout<<"-------Appointments-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Date"<<std::setw(15)<<"Time"<<std::setw(15)<<"CWID"<<std::endl;
            for(int i=0; i<ap.size();i++){
                std::cout<<std::left <<
                std::setw(20)<<ap[i].getc_name()<<std::setw(15)<<ap[i].getap_date()<<std::setw(15)<<ap[i].getap_time()<<std::setw(15)<<ap[i].getCWID()<<std::endl;
                
            }
            std::cout<<std::endl;
        }
        
        void Total_appointments(T date, T time){
            std::cout<<"total appointments for "<<date<<" at "<<time<<std::endl;
          for (int i = 0; i < ap.size(); i++) {
              if(date==ap[i].ap_date && time==ap[i].ap_time)
               std::cout<<std::left <<std::setw(20)<<ap[i].getc_name()<<std::setw(15)<<ap[i].getap_date()<<std::setw(15)<<ap[i].getap_time()<<std::setw(15)<<ap[i].getCWID()<<std::endl;   
            }
          }
           
        
        
        
        void removeRecent(){
            for (int i = 0; i < ap.size()-1; i++) {
                ap.pop_back();
            }
           std::cout<<std::endl;
        }
        
};


int main(){
 
Inventory<std::string> i1;
Item<std::string> I1("Protein Bar","05/09/2023","Snacks",4);
i1.addNewItem(I1);
Item<std::string> I2("Milk","05/12/2023","Regular",2);
i1.addNewItem(I2);
Item<std::string> I3("Cereals","09/12/2023","Snacks",5);
i1.addNewItem(I3);
i1.displayItems();
i1.updateItem("Milk","09/24/2023","Regular",3);
i1.displayItems();
i1.increaseQuantity("Cereals",10);
i1.displayItems();
try{
i1.updateItem("bar","09/12/2023","Snacks",3);
}
catch(const char* msg){
std::cout <<msg << std::endl;
}
i1.displayItems();
i1.updateItem("Cereals","09/27/2023","Regular",4);
i1.displayItems();
i1.Total();
try{
i1.removeItem("Bread");
}
catch(const char* msg){
std::cout<<msg<<std::endl;
}
try{
i1.removeItem("Milk");
}
catch(const char* msg){
std::cout<<msg<<std::endl;
}
i1.displayItems();
try{
i1.searchItem("Cereals");
}
catch(const char* msg){
std::cout<<msg<<std::endl;
}
Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
AppointmentSystem<std::string> s1;
s1.schedule(a1);
s1.schedule(a2);
s1.schedule(a3);
s1.schedule(a4);
s1.display();
s1.Total_appointments("09/12/2023","12:00PM");
Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
s1.schedule(a4);
s1.removeRecent();
s1.display();
   
}
