#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Market{
    private:
    int pcode;
    float price;
    float discount;
    string pname;

    public:
    void administrator();
    void buyer();
     void exit();
    void menu();
    void add();
    void edit();
    void rem();
    void reciept();
    void showlist();


};

void Market :: menu()

{
     m: ;
    int choice;
    string email;
    string password;

    cout<<"\t\t\t   Super Market Main Menu     \n";
    cout<<"\t\t\t   ------------         \n";
    

    cout<<"\t\t\t    Enter Choice --     \n";
    cout<<"\t\t\t  1.Administrator      \n";
    cout<<"\t\t\t  2.Buyer              \n";
    cout<<"\t\t\t  3. Exit              \n";

    cin>>choice;

    switch (choice)
    {
    case 1:
        /* code */
         cout<<"\t\t\t  Enter email :---\n";
         cin>>email;
         cout<<"\t\t\t  Enter password :---\n";
         cin>>password;
         if(email =="employee@gmail.com" && password == "user123"){
            administrator();
         }

         else{
             cout<<"\t\t\t   Invalid user email/password       \n";
         }
        break;
    case 2:
       
        buyer();
        break;
    case 3:
        exit();
        break;
    
    default:
         cout<<"\t\t\t  Please choose option as above mentioned only      \n";
        break;
    }

goto m;


}


void Market :: exit(){
    return;
}

void Market::administrator(){
    m: ;
    int choice;
    cout<<"\t\t Administrator menu        \n";
    cout<<"\t\t --------------------------\n";

     cout<<"\t\t --------------------------\n";

    cout<<"\t\t  1. ADD PRODUCT            \n";
    cout<<"\t\t -------------------------- \n";
    cout<< "\t\t 2 .DELETE PRODUCT         \n";
    cout<<"\t\t -------------------------- \n";
    cout<<"\t\t 3. MODIFY PRODUCT          \n";
    cout<<"\t\t -------------------------- \n";
    cout<<"\t\t 4. BACK TO MAIN MENU\n";


      cin>>choice;

      switch(choice){
        case 1:
            add();
            break;
        case 2:
            rem();
            break;
        case 3:
            edit();
            break;
        case 4: 
            menu();
            break;
        default:
            cout<<"\t\t INVALID INPUT   \n";
      }
      goto m;
      

}


void Market :: buyer(){
    m:;
    cout<<"\t\t ------Buyer Menu --------\n";
    cout<<"\t\t 1 BUY 2 . GO BACK\n ";
    cout<<"\t\t -------Enter Choice------ ";
    int choice;
    cin>>choice;
    cout<<"\n\t\t\t 1. Buy Products \n";

    cout<<"\t\t\t -----------------------\n";
    cout<<"\t\t\t 2.Go Back   \n";

    switch(choice){
        case 1:
            reciept();
            break;
        case 2:
            menu();
            break;
        default :
            cout<<"\t\t INVALID INVALID  \n";
    }

    goto m;

}


void Market ::add(){
    m:;
    fstream data;
    int token=0;
    int c;
    float p;
    float d;
    string na;

    cout<<"\n\t\t Enter Product code : ";
    cin>>pcode;

    cout<<"\n\t\t Enter Product Name : ";
    cin>>pname;


    cout<<"\n\t\t Enter price of product :";
    cin>>price;

    cout<<"\n\t\t Enter discount(%) of product :";
    cin>>discount;


    data.open("database.txt",ios::in);
    if(!data){
    data.open("database.txt",ios::app|ios::out);
    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<< endl;
    }

    else{
       data>>c>>na>>p>>d;

       while(!data.eof()){
        if(c==pcode){
            token++;
        }

         data>>c>>na>>p>>d;
       }


       data.close();
    }


    if(token ==1){
        goto m;
    }

    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<< endl;
        data.close();

    }

    cout<<"\n\t\t Record inserted succesfully \n";


}


void Market ::edit(){
    fstream data1,data;
    int pkey,token=0,c;
    float p,d;
    string n;

    cout<<"\t\t\t Modify Product details :\n";
     cout<<"\t\t\t Enter Product key :\n";

     cin>>pkey;
     data.open("database.txt",ios::in);
     if(!data){
        cout<<"file doesn't exist \n";

     }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;

        while(!data.eof()){
         if(pkey == pcode){
            cout<<"\t\t\t Enter new product code\n";

            cin>>c;
            cout<<"\t\t Enter name of product \n";
            cin>>n;

            cout<<"\t\tEnter price :  ";
            cin>>p;

            cout<<"\n\t\tEnter discount :  ";
            cin>>d;



            data<<c<<" "<<n<<" "<<p <<" "<<d<<endl;

            cout<<"\t\t Record edited succesfully !\n ";
            token++;


         }
         else{
            data1<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<endl;
         }

         data>>pcode>>pname>>price>>discount;
       }

       data.close();
       data1.close();
       remove("database.txt");
       rename("database1.txt","databse.txt");

       if(token ==0){
        cout<<"\t\t Record not found\n";
       }
    }
}

void Market :: rem(){
    fstream data,data1;
    int pkey,c,token =0;
    cout<<"\t\t ENTER PRODUCT KEY TO DELETE  \n";
    cin>>pkey;

     data.open("database.txt",ios::in);
     
     if(!data){
        cout<<"\t\t Record Not Found \n";

     }

     else{
        //  data.open("database1.txt",ios::app|ios::out);

         data1.open("database1.txt",ios::app|ios::out);
         data>>pcode>>pname>>price>>discount;

         while(!data.eof()){
            if(pcode == pkey){
                cout<<"\t\t Product deleted succesfully \n";
                token++;

            }

            else{
                data1<<pcode<<" "<<pname<<" "<<price<<" "<<discount<< endl; 

              }

              data>>pcode>>pname>>price>>discount;
         }

    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","databse.txt");

       if(token ==0){
        cout<<"\t\t Record not found\n";
       }


     }
    

    

}


void Market :: showlist(){

    fstream data;
    data.open("database.txt",ios::in);

    cout<<"\tAvailable Items to buy\n";
    cout<<"\tPno.  Pname  Price  dicount\n ";
    data>>pcode>>pname>>price>>discount;


    while(!data.eof()){
        cout<<"\t"<<pcode<<"\t"<<pname<<"\t"<<price<<"\t"<<discount<< endl;
        data>>pcode>>pname>>price>>discount;
    }

    data.close();



}


void Market :: reciept(){
    fstream data;

    int arrc[100];
    int arrq[100];

    int c =0;
    char choice;
    float amount=0,dis =0,total =0,final =0;

   cout<<"\t\t Reciept \n";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"Empty Databse \n";
    }
    else{
        data.close();
        showlist();
        cout<<"_____________________________\n";
        cout<<"     Place the order         \n";
        cout<<"      ------------           \n";
        cout<<"_____________________________\n";

        do
        {
            /* code */
            m:;
            cout<<"\n\tEnter Product code :";
            cin>>arrc[c];
            cout<<"\n\t Enter Product Quantity: ";
            cin>>arrq[c];

           
            c++;

            cout<<"\t Want to purchase more product or not ?Y or N\n";
            cin>>choice;
        } while (choice =='Y'||choice=='y');


        cout<<"\nSNo.       Item     Quantity  price  amount  Total \n"<<endl;

        for(int i=0;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;

            while(!data.eof()){
                if(pcode ==arrc[i]){
                    amount =price * arrq[i];
                    discount =amount - amount*discount /100;

                    total = total +discount;
                    final += total;
                    

                    cout<<"\n"<<pcode<<"       "<<pname<<"        "<<arrq[i]<<"         "<<price<<"       "<<amount<<"        "<<total<<"\t"<< endl;

                }

                data>>pcode>>pname>>price>>discount;
            }
            data.close();
         
           

        }

        cout<<"\n\n Final Amount to be paid : \t"<<final<<endl<<endl;
        
    }
}
int main(){

    Market a;
    a.menu();
    
    return 0;
}