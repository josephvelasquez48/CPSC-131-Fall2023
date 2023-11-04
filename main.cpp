#include<iostream>
#include<memory>
#include<vector>
#include<string>

template<typename T> class Tab{
    public:
        std::string url;
        std::string name;
        T memory;
        std::shared_ptr<Tab<T> >next;
        std::shared_ptr<Tab<T> >prev;

};
template<typename T> class Browser{
    public:
        std::shared_ptr<Tab<T> > head;
        std::shared_ptr<Tab<T> > tail;
        std::shared_ptr<Tab<T> >current;
        std::vector<std::shared_ptr<Tab<T> > > bookmarks;
        
        
void moveCurrentToFirst(){
    std::shared_ptr<Tab<T> > prev = head;
    std::shared_ptr<Tab<T> > temp = current;
    std::shared_ptr<Tab<T> > new_= std::make_shared<Tab<T> >();
    head->prev=new_;
    new_->next=head;
    head=new_;
    new_->name=temp->name;
    new_->url=temp->url;
    new_->memory=temp->memory;
    tail=tail->prev;
    tail->next=nullptr;
    current->prev=new_->prev;
    current->next=new_->next;
}

void closeCurrentTab(){
    std::shared_ptr<Tab<T> > prev = head;
    std::shared_ptr<Tab<T> > temp = current;
    if(current==head){
        head=head->next;
        head->prev=nullptr;
        current=head;
        std::cout<<"Tab closed = "<<temp->name<<std::endl;
    }
    else if(current==tail){
        tail=tail->prev;
        tail->next=nullptr;

        current=tail;
        std::cout<<"Tab closed = "<<temp->name<<std::endl;
    }
    else{
        current->prev->next=current->next;
        current=current->next;
        current->prev=current->prev->prev;
        std::cout<<"Tab closed = "<<temp->name<<" with memory size = "<<temp->memory<<std::endl;

    }

}

void deleteTab(){

    std::shared_ptr<Tab<T> > curr = std::make_shared<Tab<T> >();
    std::shared_ptr<Tab<T> > max = std::make_shared<Tab<T> >();
    std::shared_ptr<Tab<T> > temp = std::make_shared<Tab<T> >();
    curr=head;

    max->memory = curr->memory;
    max->memory=0;
    while (curr->next != nullptr) {
        if (curr->memory > max->memory) {
            max->memory = curr->memory;
            max->name = curr->name;
            max->url = curr->url;
            temp = curr;
            current=temp;
        }
        curr = curr->next;
    }

    closeCurrentTab();

}
    
void showBookmarkTab(){
    std::cout<< "Bookmarks:" <<std::endl;
    for (int i = 0; i < bookmarks.size(); i++){
        std::cout << bookmarks[i]->name<< "("<<bookmarks[i]->url<< ")"<< std::endl;
    }
}

void bookmarkCurrent(){
    std::shared_ptr<Tab<T> > curr;
    curr=current;
    std::cout<< "Bookmark added: " << curr->name<<std::endl;
    bookmarks.push_back(curr);

}

double total_memory(){
    std::shared_ptr<Tab<T> > curr;
    curr = head;
    double temp=0;
    while(curr!= nullptr){
        temp+=curr->memory;
        curr = curr->next;
    }

    return temp;
}

void switchToNextTab(){
    if(current==nullptr){
        std::cout<<"Linked List is empty"<<std::endl;
    }
    else if(current->next==nullptr){
        std::cout<<"No next Tab"<<std::endl;
    }
    else {
        current=current->next;
        std::cout<<current->url<<std::endl;
        std::cout<<current->name<<std::endl;
        std::cout<<current->memory<<std::endl;
    }
}

void switchToPrevTab(){
    if(current==nullptr){
        std::cout<<"Linked List is empty"<<std::endl;
    }
    else if(current->prev==nullptr){
        std::cout<<"No previous Tab"<<std::endl;
    }
    else {
        current=current->prev;
        std::cout<<current->url<<std::endl;
        std::cout<<current->name<<std::endl;
        std::cout<<current->memory<<std::endl;
    }
}

void addNewTab(std::string a,std::string b,T c){
    std::shared_ptr<Tab<T> > new_node = std::make_shared<Tab<T> >();

    if(head==nullptr){
        new_node->url = a;
        new_node->name = b;
        new_node->memory = c;
        new_node->next = nullptr;
        head = new_node;
        tail = new_node;
        current = new_node;
    }
    else{
        new_node->url = a;
        new_node->name = b;
        new_node->memory = c;
        new_node->next = nullptr;
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        current = new_node;
        current->prev=new_node->prev;
        current->next=new_node->next;
    }
}

void display(){
    std::shared_ptr<Tab<T> > curr;
    curr = head;
    std::cout<<"Browser tab list = "<<std::endl;
    while(curr){
        std::cout<<"| "<<curr->name<<" x|-->";
        curr = curr->next;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}


};
int main(){
    Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    b1.bookmarkCurrent();
    b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.showBookmarkTab();
    b1.moveCurrentToFirst();
    b1.display();
    b1.deleteTab();
    b1.display();
    std::cout<<"Switch to next tab = "<<std::endl;
    b1.switchToNextTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
    b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.bookmarkCurrent();
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
return 0;
}