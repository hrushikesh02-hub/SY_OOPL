#include<iostream>
using namespace std;

class BookShop
{
	public : 
		int stock,id;
		float price;
		string  b_name;
		string a_name;
		string p_name;
		string c_name;
		long long m_num;
		string city;
		string c;
		
		BookShop()
		{
			stock=0;
			price=0;
			b_name="";
			a_name="";
			p_name="";
		}
		
		void setdata(int s,int ID,float pr,string a,string b,string p)
		{
			id=ID;
			stock=s;
			price=pr;
			b_name=b;
			a_name=a;
			p_name=p;
		}
		
		void display()
		{
			cout<<"\nBook ID : "<<id<<endl;
			cout<<"Book Title : "<<b_name<<endl;
			cout<<"Book Author : "<<a_name<<endl;
			cout<<"Book Publisher : "<<p_name<<endl;
			cout<<"Available Stock : "<<stock<<endl;
			cout<<"Book Price : "<<price<<endl;
		}
		
		void purchase()
		{
			int copies;
			string c;
			cout<<"Book Title : "<<b_name<<endl;
			cout<<"Book Author : "<<a_name<<endl;
			cout<<"Book Publisher : "<<p_name<<endl;
			cout<<"Book Price : "<<price<<endl;
			cout<<"How many copies do you want ? : ";
			cin>>copies;
			if(stock<copies)
			{
				cout<<"Book Out of Stock !"<<endl;
			}
			else
			{
				float total_cost=copies*price;
				cout<<"Total price of "<<copies<<" copies is "<<total_cost<<endl;
				stock-=copies;
				cout<<"Do you want to purchase this book ?(yes/no) : ";
				cin>>c;
				if(c=="yes")
				{
					cout<<"Enter Your Details : "<<endl;
					cout<<"Enter your name : ";
					cin>>c_name;
					cout<<"Enter your mobile number : ";
					cin>>m_num;
					cout<<"Enter your city : ";
					cin>>city;
					cout<<"Book Purchased Successfully !"<<endl;
				}
				else
				{
					cout<<"Thank You........Waiting for you !"<<endl;
				}
			}
		}
		
		void c_details()
		{
			cout<<"Customer Name : "<<c_name;
			cout<<"Mobile Number : "<<m_num;
			cout<<"City : "<<city;
			cout<<"Book Purchased : "<<b_name;
		}
};
		
int main()
{
	int choice,total_books=0;
	int found=0;
	string bookname,authorname;
	BookShop book[100];
	cout<<"------------Book Inventory System------------"<<endl;
	while(true)
	{
		cout<<"\n1. Add New Book"<<endl;
		cout<<"2. Search Book"<<endl;
		cout<<"3. Purchase Book"<<endl;
		cout<<"4. Display Available Books"<<endl;
		cout<<"5. Display Customer Details"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : 
				if(total_books>=100)
				{
					cout<<"Books limit reached !"<<endl;
					cout<<"You cannot add more books"<<endl;
				}
				else 
				{
					int stock,id;
					float price;
					string  b_name;
					string a_name;
					string p_name;
					
					cout<<"Enter Book ID : ";
					cin>>id;
					cout<<"Enter Book Title : ";
					cin>>b_name;
					cout<<"Enter Book Author : ";
					cin>>a_name;
					cout<<"Enter Book Publisher : ";
					cin>>p_name;
					cout<<"Enter Stock : ";
					cin>>stock;
					cout<<"Enter Book Price : ";
					cin>>price;
					
					book[total_books].setdata(stock,id,price,a_name,b_name,p_name);
					total_books++;
					cout<<"Book Added Successfully"<<endl;
				}
				break;
				
			case 2 : 
				cout<<"Enter Book Name : ";
				cin>>bookname;
				cout<<"Enter Author Name : ";
				cin>>authorname;
				for(int i=0;i<total_books;i++)
				{
					if(book[i].b_name==bookname && book[i].a_name==authorname)
					{
						found=1;
						book[i].display();
						break;
					}
				}
				if(!found)
				{
					cout<<"Book Not Found !"<<endl;
				}
				
				break;
			
			case 3 : 
				cout<<"Enter Book Name : ";
				cin>>bookname;
				cout<<"Enter Author Name : ";
				cin>>authorname;
				for(int i=0;i<total_books;i++)
				{
					if(book[i].b_name==bookname && book[i].a_name==authorname)
					{
						found=1;
						book[i].purchase();
						break;
					}
				}
				if(!found)
				{
					cout<<"Book Not Found !"<<endl;
				}
				
				break;
				
			case 4 : 
				for(int i=0;i<total_books;i++)
				{
					book[i].display();
				}
				break;
				
			case 5 :
				string name;
				cout<<"Enter Customer Name : ";
				cin>>name;
				for(int i=0;i<total_books;i++)
				{
					if(name==book[i].c_name)
					{
						found=1;
						book[i].c_details();
						break;
					}
				}
				if(!found)
				{
					cout<<"Customer Not Found !"<<endl;
				}
				break;
			
			case 6 :
				cout<<"Thank You..........!"<<endl;
				return 0;
			
			default : 
				cout<<"Invalid Choice !"<<endl;
				
		}
	}
}
				
				
					
					
			
