#include<iostream>
#include<vector>
#include<string>


class Stack{
    public:
        
        std::vector<char> nodes;
        
        void push(char node){
         nodes.push_back(node);   
        }
        
        void pop(){
            if (!Empty()) {
                //char node = nodes.back();
                nodes.pop_back();
            }
        
        }
        
        bool Empty(){
            return nodes.empty();
        }
        
        char Top(){
            if (!Empty()) {
            return nodes.back();
        }
        return -1;
        }
        
        
        
        void validPara(std::string str1){
            Stack stack1;
            Stack stack2;
            char x;
            
            for(char i : str1){
                  if(i=='('||i=='['||i=='{'){
                      stack1.push(i);
                  }else if(i==')'||i==']'||i=='}'){
                      x=stack1.Top();
                      if(x=='(' && i==')'){
                          stack1.pop();
                      }else if(x=='{' && i=='}' ){
                          stack1.pop();
                          
                      }else if(x=='[' && i==']'){
                          stack1.pop();
                      }else{
                          if(!stack1.Empty()){
                              while(!stack1.Empty()){
                              stack2.push(stack1.Top());
                              stack1.pop();
                              if(stack1.Top()=='(' && i==')'){
                                stack1.pop();
                              }else if(stack1.Top()=='{' && i=='}' ){
                                stack1.pop();
                              }else if(stack1.Top()=='[' && i==']'){
                                stack1.pop();
                              }
                              }
                          }
                              else{
                                stack1.push(i);
                                std::cout<<"invalid"<<std::endl;
                                return;
                              }
                          
                      }
                  }else{
                      stack1.push(i);
                      stack1.pop();
                  }
            }
                       
                          if(!stack2.Empty()){
                              while(!stack2.Empty()){
                              stack1.push(stack2.Top());
                              stack2.pop();
                              }
                          }
                         
            
            if(stack1.Empty()){
                std::cout<<"valid"<<std::endl;
            }else{
                std::cout<<"invalid"<<std::endl;
            }
        }
        
        
        void minPara(std::string str1){
            Stack stack1;
            Stack stack2;
            char x;
            
            for(char i : str1){
                  if(i=='('||i=='['||i=='{'){
                      stack1.push(i);
                  }else if(i==')'||i==']'||i=='}'){
                      x=stack1.Top();
                      if(x=='(' && i==')'){
                          stack1.pop();
                      }else if(x=='{' && i=='}' ){
                          stack1.pop();
                          
                      }else if(x=='[' && i==']'){
                          stack1.pop();
                      }else{
                          if(!stack1.Empty()){
                              while(!stack1.Empty()){
                              stack2.push(stack1.Top());
                              stack1.pop();
                              if(stack1.Top()=='(' && i==')'){
                                stack1.pop();
                              }else if(stack1.Top()=='{' && i=='}' ){
                                stack1.pop();
                              }else if(stack1.Top()=='[' && i==']'){
                                stack1.pop();
                              }
                              }
                          }
                              else{
                                stack1.push(i);
                                std::cout<<stack1.nodes.size()<<std::endl;
                                return;
                              }
                          
                      }
                  }else{
                      stack1.push(i);
                      stack1.pop();
                  }
            }
                       
                          if(!stack2.Empty()){
                              while(!stack2.Empty()){
                              stack1.push(stack2.Top());
                              stack2.pop();
                              }
                          }
                         
            
            if(stack1.Empty()){
                std::cout<<stack1.nodes.size()<<std::endl;
            }else{
                std::cout<<stack1.nodes.size()<<std::endl;
            }
        }
        
        void scorePara(std::string str1){
            Stack stack1;
            Stack stack2;
            char x;
            int count=0;
            for(char i : str1){
                  if(i=='('||i=='['||i=='{'){
                      
                      stack1.push(i);
                  }else if(i==')'||i==']'||i=='}'){
                      
                      x=stack1.Top();
                      if(x=='(' && i==')'){
                          count+=1;
                          stack1.pop();
                      }else if(x=='{' && i=='}' ){
                          count+=1;
                          stack1.pop();
                          
                      }else if(x=='[' && i==']'){
                          count+=1;
                          stack1.pop();
                      }else{
                          if(!stack1.Empty()){
                              while(!stack1.Empty()){
                                  count+=1;
                              stack2.push(stack1.Top());
                              stack1.pop();
                              if(stack1.Top()=='(' && i==')'){
                                stack1.pop();
                                //count+=1;
                              }else if(stack1.Top()=='{' && i=='}' ){
                                stack1.pop();
                                //count+=1;
                              }else if(stack1.Top()=='[' && i==']'){
                                stack1.pop();
                                //count+=1;
                              }
                              }
                          }
                              else{
                                stack1.push(i);
                                std::cout<<count<<std::endl;
                                return;
                              }
                          
                      }
                  }else{
                      stack1.push(i);
                      stack1.pop();
                  }
            }
                       
                          if(!stack2.Empty()){
                              while(!stack2.Empty()){
                              stack1.push(stack2.Top());
                              stack2.pop();
                              }
                          }
                         
            
            if(stack1.Empty()){
                std::cout<<count<<std::endl;
            }else{
                std::cout<<count<<std::endl;
            }
       
    
        }
        
        int indexError(std::string str1){
          Stack stack1;
            Stack stack2;
            char x;
            int count=-1;
            for(char i : str1){
                
                  if(i=='('||i=='['||i=='{'){
                      count+=1;
                      stack1.push(i);
                  }else if(i==')'||i==']'||i=='}'){
                      x=stack1.Top();
                      if(x=='(' && i==')'){
                          count+=1;
                          stack1.pop();
                      }else if(x=='{' && i=='}' ){
                          count+=1;
                          stack1.pop();
                          
                      }else if(x=='[' && i==']'){
                          count+=1;
                          stack1.pop();
                      }else{
                          if(!stack1.Empty()){
                              while(!stack1.Empty()){
                              stack2.push(stack1.Top());
                              stack1.pop();
                              if(stack1.Top()=='(' && i==')'){
                                stack1.pop();
                              }else if(stack1.Top()=='{' && i=='}' ){
                                stack1.pop();
                              }else if(stack1.Top()=='[' && i==']'){
                                stack1.pop();
                              }
                              }
                          }
                              else{
                              count+=1;
                                stack1.push(i);
                                std::cout<<count<<std::endl;
                                return count;
                              }
                          
                      }
                  }else{
                      count+=1;
                      stack1.push(i);
                      stack1.pop();
                  }
            }
              if(!stack2.Empty()){
                              while(!stack2.Empty()){
                              stack1.push(stack2.Top());
                              count+=1;
                              stack2.pop();
                              }
                          }          
                         
                         
            
            if(stack1.Empty()){
                return count;
                
            }else{
                return count;
                
            }
        
        }
};



class Queue{
    public:
        
        std::vector<std::string> queue;
        
        
        
 void push(std::string str1){
         queue.push_back(str1);   
        }
 
 void pop(){
            if (!Empty()) {
                ;
                queue.erase(queue.begin());
            }
        
        }
 
 bool Empty(){
            return queue.empty();
        }
        
 std::string Front(){
     std::string a;
            if (!Empty()) {
                a = queue[0];
            return a;
        }
        return "Queue is empty";
        }
 
 
 void enqueue(std::string str1) {
     
    
     for(int i=0;i<str1.length();i+=8){
        std::string chunk = str1.substr(i, 8);
        std::reverse(chunk.begin(), chunk.end());
        push(chunk);
         
     }
     std::cout<<"Encrypted message: "<<std::endl;
     for(int i=0; i<queue.size();i++){
         std::cout<<queue[i]<<" ";
         
     }
     std::cout<<std::endl;
 }
 
 void processMsg() {

     std::string message;
     
    while (!Empty()) {
      std::string chunk = Front();
      pop();
      std::reverse(chunk.begin(), chunk.end());
      message += chunk;
      
    }
    
     std::cout << "Processed Message: " <<std::endl;
     std::cout <<message << std::endl;
 }
};






int main(){

Stack s1;
s1.validPara("(([]))");
s1.minPara("(([]))");
s1.scorePara("(([]))");
s1.validPara("(([])");
std::cout<<std::endl;
std::cout<<s1.indexError("(([))")<<std::endl;
s1.minPara("(([])");
s1.validPara("(([{}))");
std::cout<<std::endl;
std::cout<<s1.indexError("(([[}])")<<std::endl;
s1.minPara("(([{}))");
s1.scorePara("(([{}))");
std::cout<<std::endl;
std::cout<<std::endl;
std::cout<<s1.indexError("({}[]()[)")<<std::endl;
s1.validPara("(([))");
s1.minPara("(([))");
std::cout<<std::endl;
std::cout<<s1.indexError("[({)]")<<std::endl;
s1.validPara("(([{[{({})}]}]))");
s1.minPara("(([{[{({})}]}]))");
s1.scorePara("(([{[{({})}]}]))");
s1.validPara("(([[{[{({})}]))");
s1.validPara("(([[{[{({})}]}])]))");
s1.scorePara("(([[{[{({})}]}])]))");
std::cout<<std::endl;
std::cout<<s1.indexError("(([[{{({})]}])]))")<<std::endl;
s1.validPara("(())");
s1.validPara("(())");
s1.validPara("void function(){}");
s1.scorePara("void function(){}");
s1.validPara("void function(");
s1.minPara("void function(");
s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.scorePara("void function(std::string expre){if(expre){return 1;}else{return 0;}}");
s1.validPara("void function(std::string expre){if(expre){return 1;}else{return 0;}");
s1.validPara("void function(std::string expre){if(expre){return 1;else{return 0;");
s1.minPara("void function(std::string expre){if(expre){return 1;else{return 0;");
std::cout<<s1.indexError("void function(std::string expre){if(expre){return 1;else{return 0;")<<std::endl;

Queue q1;
q1.enqueue("This is a secure message.");
q1.processMsg();
q1.enqueue("The product I received is damaged. What should I do?");
q1.processMsg();
q1.enqueue("I need assistance with setting up my new device");
q1.processMsg();
q1.enqueue("The website is not loading properly on my browser.");
q1.processMsg();
q1.enqueue("I accidentally placed the wrong order. Can it be canceled?");
q1.processMsg();
q1.enqueue("This is your project3. Have a happy thanksgiving!!! Hahaha");
q1.processMsg();
q1.enqueue("I forgot my password and can't reset it. Help, please! Do you provide technical support for mobile devices?");
q1.processMsg();
q1.enqueue("The software update is causing issues on my computer. The response time on your website is very slow.");
q1.processMsg();

return 0;
}
