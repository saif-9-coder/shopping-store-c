#include<iostream>
#include<fstream>
using namespace std;
void main_menu();
struct node 
{
	string id;
	string catagery;
	string name;
	int price;
	int quantity;
	struct node * next;
};
class user
{
	protected:
	string person_name;
	int price;
	string catagery;
	int quantity;
	struct node * next;
    node *head;
	string name;
	string id;
	public:
	 user()
    {
        head = NULL;
    }
    //display all items from shop
	void display()
	{
	  int i=0;
      ifstream file;
	  file.open("product list.txt",ios::in);
	  file>>id>>name>>price>>catagery>>quantity;
	  if(file.eof())
	  {
	  	cout<<"\t\t<<<<.......File is Emprt.......>>>>";
	  }
	  while(!file.eof())
	  { 
	    if(i==0)
	    {
	    	cout<<"ID\tName\tPrice\tCatagery"<<" "<<"Quantity"<<endl;
		}
	  	cout<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<quantity<<endl;
	    file>>id>>name>>price>>catagery>>quantity;
	    i++;
	  }	
	}

	
};
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class admin:public user
{ 
private:
int ch; 
public:
	//add items in store
    void add_items()
    {
    	ofstream file;
		file.open("product list.txt",ios::app);
    	cout<<"Enter Product ID=";
    	cin>>id;
    	cout<<"Enter Product Name=";
    	cin>>name;
    	cout<<"Enter Product Price=";
    	cin>>price;
    	cout<<"Enter Product Catagery=";
    	cin>>catagery;
    	cout<<"Enter Product Quantity=";
    	cin>>quantity;
    	file<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<quantity<<endl;
    	if (head==NULL)
    	{
    		node * temp = new node () ;
    		head=temp;
    		temp->id = id;
    		temp->name = name;
    		temp->price = price;
    		temp->catagery = catagery;
    		temp->quantity = quantity;
    		temp ->next= NULL;
		}
		else
		{
			node * temp = new node ();
			node * ptr=head;
			while (ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->id = id;
    		temp->name = name;
    		temp->price = price;
    		temp->catagery = catagery;
    		temp->quantity = quantity;
			temp->next=NULL;
		}
	}
	//...........................................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//	void add_to_file ()
//	{
//		ofstream file;
//		file.open("product list.txt",ios::app);
//		if(head==NULL)
//		{
//			cout<<"Linked List is empty"<<endl;
//		}
//		else
//		{
//			node * temp=head;
//			while(temp!=NULL)
//			{
//				file<<temp->id<<"\t"<<temp->name<<"\t"<<temp->price<<"\t"<<temp->catagery<<"\t"<<temp->quantity<<endl;	
//				temp=temp->next;
//			}
//					cout<<"\t\tYour Data Sucessfully Add To File ....>>"<<endl;
//		}
//	}
//........................................................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//delete items from store
 void del_items()
 {
 	display();
 	string new_id;
  	cout<<"Enter ID of Product =";
  	cin>>new_id;
  	ofstream filee;
	filee.open("newproduct list.txt",ios::app);
  	ifstream file;
	file.open("product list.txt",ios::in);
	file>>id>>name>>price>>catagery>>quantity;
	while(!file.eof())
	  {
	
	  	if(new_id==id)
	  	{
	  		cout<<"element found and delete"<<endl;
		}
		else
		{
	
	  	filee<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<quantity<<endl;
		}
		   file>>id>>name>>price>>catagery>>quantity;
	  }	
	  file.close();
	  filee.close();
  	remove("product list.txt");
  	rename("newproduct list.txt","product list.txt");
  	
 }
 //...............>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>..
 //modify item in store
 void modify_items()
 {
 	display();
 	string new_id;
  	cout<<"Enter ID of Product=";
  	cin>>new_id;
  	ofstream filee;
	filee.open("newproduct list.txt",ios::app);
  	ifstream file;
	file.open("product list.txt",ios::in);
    file>>id>>name>>price>>catagery>>quantity;
	while(!file.eof())
	  {
	
	  	if(new_id==id)
	  	{
	  		cout<<"\t\tEnter (1) >> Update ID"<<endl;
	  		cout<<"\t\tEnter (2) >> Update Name"<<endl;
	  		cout<<"\t\tEnter (3) >> Update Price"<<endl;
	  		cout<<"\t\tEnter (4) >> Update Catagery"<<endl;
	  		cout<<"\t\tEnter (5) >> Update Quantity"<<endl;
	  		cout<<"Enter Your Chosie"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"\t<<<<<< Enter New ID Of Product >>>>>>"<<endl;
			cin>>id;
			
			break;
		case 2 :
				cout<<"\t<<<<<< Enter New Name of Product >>>>>>"<<endl;
			cin>>name;
         
		  break;
		  	case 3 :
        	cout<<"\t<<<<<< Enter New Price Of Product >>>>>>"<<endl;
			cin>>price; 
		  break;
		  	case 4 :
        	cout<<"\t<<<<<< Enter New Catagery Of product >>>>>>"<<endl;
			cin>>catagery;
		  break;
		  	case 5 :
        cout<<"\t<<<<<< Enter New Quantity Of Product >>>>>>"<<endl;
			cin>>quantity;
		  break;
		  
	}
	  		filee<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<quantity<<endl;
	  		cout<<"\t\tProduct Details Updated...."<<endl;
		}
		else
		{
	
	  	filee<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<quantity<<endl;
		}
		   	 file>>id>>name>>price>>catagery>>quantity;
	  }	
	  file.close();
	  filee.close();
  	remove("product list.txt");
  	rename("newproduct list.txt","product list.txt");
 }
 //admin function which call all the functins of admin
  void admin_menu()
  {

 	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|               ADMIN MENU                  |"<<endl;
	cout<<"\t\t============================================"<<endl;
	cout<<endl<<"ENTER (1) >>>> ADD ITEMS IN SHOP"<<endl;
//	cout<<"ENTER (2) >>>> Add ITEMS IN FILE"<<endl;
	cout<<"ENTER (2) >>>> DISPLAY ITEMS IN SHOP"<<endl;
	cout<<"ENTER (3) >>>> DELETE ITEMS FROM SHOP"<<endl;
	cout<<"ENTER (4) >>>> MODIFIY DETAILS OF ITEMS IN SHOP"<<endl;
	cout<<"ENTER (5) >>>> BACK To ADMIN PAGE"<<endl;
	cout<<"Enter Your Choise=";
	cin>>ch;
	switch(ch)
	{
		case 1:
			add_items();
			break;
//		case 2 :
//			add_to_file();

//			break;
		case 2 :
         display();
		  break;
		  	case 3 :
         del_items();
		  break;
		  	case 4 :
         modify_items();
		  break;
		  	case 5 :
         main_menu();
		  break;
		  
	}
		admin_menu();
  }	
};
class customer:public user
{
	private:
		int total_quantity;
		int total_price;
		int total_items;
		string info[10];
	public:
		customer()
		{
		 head = NULL;
		total_quantity=0;
		total_price=0;
		total_items=0;	
		}
		//customers information
	void customer_info()
	{
	   cout<<"Please Enter Your Firts Name= ";
	   cin>>info[1];
	   cout<<"Please Enter Your Last Name= ";
	   cin>>info[2];
	   cout<<"Enter Your phone Number=";
	   cin>>info[3];
	   ofstream filee;	
	   	filee.open("Customers info list.txt",ios::app);
	   	filee<<"_____________________________________________________"<<endl;
	    filee<<"Name of Customer=\t"<<info[1]<<" "<<info[2]<<endl<<"phone no=\t"<<info[3]<<endl;
	}	
	//.....................................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//bill of items which buy from customers
		void bill()
	{
	    ofstream file;
		file.open("cutomers bill list.txt",ios::app);
		cout<<"                                   ***                                            "<<endl;
		cout<<"----------------------------------------------------------------------------------"<<endl;
	    cout<<"Name ="<<info[1]<<"-"<<info[2]<<"\t\tPhone No="<<info[3]<<endl;
	    cout<<"----------------------------------------------------------------------------------"<<endl;
	    file<<"                                                                                  "<<endl;
	    file<<"                                   ***                                            "<<endl;
	    file<<"                                                                                  "<<endl;
	    file<<"----------------------------------------------------------------------------------"<<endl;
	    file<<"Name ="<<info[1]<<"-"<<info[2]<<"\t\tPhone No="<<info[3]<<endl;
	    file<<"----------------------------------------------------------------------------------"<<endl;
		if(head==NULL)
		{
			cout<<"Linked List is empty"<<endl;
		}
		else
		{
			node * temp=head;
			while(temp!=NULL)
			{
				total_quantity=total_quantity+temp->quantity;
	  	        total_price=total_price+(temp->price*temp->quantity);
	  	        total_items++;
				file<<temp->id<<"\t"<<temp->name<<"\t"<<temp->price<<"\t"<<temp->catagery<<"\t"<<temp->quantity<<endl;	
				cout<<temp->id<<"\t"<<temp->name<<"\t"<<temp->price<<"\t"<<temp->catagery<<"\t"<<temp->quantity<<endl;	
				temp=temp->next;
			}
		}
//	  while(!file.eof())
//	  {
//	  	total_quantity=total_quantity+quantity;
//	  	total_price=total_price+(price*quantity);
//	  	total_items++;
//	  	filee<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<quantity<<endl;
//	    file>>id>>name>>price>>catagery>>quantity;
//	  }		

      file<<"----------------------------------------------------------------------------------"<<endl;
	  file<<"Total items="<<total_items<<"\tTotal Quantity="<<total_quantity<<"\t\t\tTotal Price="<<total_price<<"(PKR)"<<endl;
	  file<<"----------------------------------------------------------------------------------"<<endl;
	  cout<<"----------------------------------------------------------------------------------"<<endl;
	  cout<<"Total items="<<total_items<<"\tTotal Quantity="<<total_quantity<<"\t\t\tTotal Price="<<total_price<<"(PKR)"<<endl;
	  cout<<"----------------------------------------------------------------------------------"<<endl;
	  file.close();
	}
//,,,,,,,,,,,,,,,,,.........................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//buy items from store
		void buy_items()
		{
		display();
	int buy_quantity;	
 	string new_id;
  	cout<<"Enter ID of Product=";
  	cin>>new_id;
  	ofstream filee;
	filee.open("sale product list.txt",ios::app);
	ofstream file2;
	file2.open("newproduct list.txt",ios::app);
  	ifstream file;
	file.open("product list.txt",ios::in);
    file>>id>>name>>price>>catagery>>quantity;
	while(!file.eof())
	  {
	
	  	if(new_id==id)
	  	{
	  		
	  		cout<<"Enter Quantity Of Items=";
	  		cin>>buy_quantity;
	  		filee<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<buy_quantity<<endl;
	  		cout<<"\t\tBuy Items Sucessfully...."<<endl;
	  			if (head==NULL)
    	{
    		node * temp = new node () ;
    		head=temp;
    		temp->id = id;
    		temp->name = name;
    		temp->price = price;
    		temp->catagery = catagery;
    		temp->quantity = buy_quantity;
    		temp ->next= NULL;
		}
		else
		{
			node * temp = new node ();
			node * ptr=head;
			while (ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->id = id;
    		temp->name = name;
    		temp->price = price;
    		temp->catagery = catagery;
    		temp->quantity = buy_quantity;
			temp->next=NULL;
		}
	  		quantity=quantity-buy_quantity;
	  		file2<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<quantity<<endl;
		}
		else
		{
			file2<<id<<"\t"<<name<<"\t"<<price<<"\t"<<catagery<<"\t"<<quantity<<endl;
		}
		   	 file>>id>>name>>price>>catagery>>quantity;
	  }	
	  file.close();
	  filee.close();	
	  file2.close();	
	remove("product list.txt");
  	rename("newproduct list.txt","product list.txt");
	}
	//.................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	//customer menu which call all the function of customer class
	void customer_menu()
	{
		int ch;
	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|             CUSTOMER MENU                 |"<<endl;
	cout<<"\t\t============================================"<<endl;
	cout<<endl<<"ENTER (1) >>>> WATCH ITEMS IN STORE"<<endl;
	cout<<"ENTER (2) >>>> BUY ITEMS FROM STORE"<<endl;
	cout<<"ENTER (3) >>>> BILL OF ITEMS"<<endl;
	cout<<"ENTER (4) >>>> BACK To MAIN MENU"<<endl;
	cout<<"Enter Your Choise"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			display();
			break;
		case 2 :
			buy_items();
			break;
			case 3 :
			bill();
		  break;
		case 4 :
			main_menu();
		  break;
		  
			
	}
	customer_menu();
	}
};
//.............................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//main_menu is a function which call admin and cutomers
void main_menu()
{   
    int pin;
	int ch;
	admin a;
	customer c;
    cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|     ****     DADA POTA STORE     ****     |"<<endl;
	cout<<"\t\t============================================"<<endl;
	cout<<endl<<"\t\t<<<<<<<....(  << MAIN MENU >>   )....>>>>>>>>"<<endl;
	cout<<endl<<"ENTER (1) >>>>>> ADMIN "<<endl;
	cout<<"ENTER (2) >>>>>> CUSTOMER "<<endl;
	cout<<"ENTER (3) >>>>>> EXIT "<<endl;
	cout<<"\nEnter Your choice >>>";
	cin>>ch;
	switch(ch){
	case 1:
		//password which allow to accsses to modify store
     cout<<"Enter 4 Digit Pin .....>>>>=";
     cin>>pin;
     if(pin==1234)
     {
       a.admin_menu();
	 }
	 else
	 {
	 	cout<<"Enter Correct Password ....<<<"<<endl;
	 	main_menu();
	 }
	
		break;

	case 2:
		c.customer_info();
		c.customer_menu();
	    break;

    case 3:
    	cout<<"\n\n\t\t\t\t\tThank You\t\t\t\t";
    	break;
   
 	}
 	main_menu();
}
main()
{
 main_menu();
}

