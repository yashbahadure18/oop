#include<iostream>
#include<cstring>
using namespace std;
class publication{
    protected:
    string title;
    float price;
    public:
    void get(){
        cout<<"Enter Title of Publication : ";
        cin>>title;cout<<""<<endl;
        cout<<"Enter Price of Publication : ";
        cin>>price;cout<<""<<endl;
    }
    void put(){
        try{
            if (title.length()<=1){
                throw title;
            }  
        }catch(string exp){
            title="No Name";
        }
        cout<<"Publication name : "<<title<<endl;
        try{
            if (price<=0){
                throw price;
            }  
        }catch(float exp){
            price=0;
        }
        cout<<"Price : "<<price<<endl;
    }
};
class book:public publication{
    int pg_count;
    public:
    void get_page(){
        publication::get();
        cout<<"Enter Page count : ";
        cin>>pg_count;cout<<""<<endl;
    }
    void put_page(){
        try
        {
            if (pg_count<=0)
            {
                throw pg_count;
            }
            
        }
        catch(int exp)
        {
            pg_count=0;
        }
        publication::put();
        cout<<"Page Count : "<<pg_count<<endl;
    }
};
class tape:public publication{
    protected:
    int minu;
    public:
    void get_min(){
        publication::get();
        cout<<"Enter duration in minutes : ";
        cin>>minu;cout<<""<<endl;
    }
    void put_min(){
        try
        {
            if (minu<=0){
                throw minu;
            }
        }
        catch(int exp)
        {
            minu=0;
        }
        publication::put();
        cout<<"Duration (in minutes) : "<<minu<<endl;

        
    }

};
int main(){
    book b1;
    tape t1;
    cout<<"************Enter Book data**********"<<endl;
    b1.get_page();
    cout<<"************Enter Tape Data**********"<<endl;
    t1.get_min();
    cout<<"************Book data****************"<<endl;
    b1.put_page();
    cout<<"************Tape data****************"<<endl;
    t1.put_min();
    return 0;
}