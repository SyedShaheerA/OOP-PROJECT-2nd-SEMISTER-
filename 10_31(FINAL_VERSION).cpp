#include <fstream> 
#include <istream> 
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include<conio.h>
#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>

using namespace std;


void VIEW_AS_Byer(string password, string Cnic); 
void VIEW_AS_Seller(string password,string Cnic);
void menuOf_Seller_Or_Register(string password, string Cnic);
void view_As_Admin();
void checkcnic(string cnic5);
int menu();
void login();
void  view_As_Admin();
void checkaddress(string x);



//void menuOf_Seller_Or_Register(string password, int Cnic);

void loader(string xyz);
string inputstring()
{
	string z;
	cin >> z;
	return z;
}

int inputint()
{
	int z;
	cin >> z;
	return z;
}

long int inputlongint()
{
	long int z;
	cin >> z;
	return z;
}

double inputdouble()
{
	double a;
	cin>> a;
	return a;
}


float inputfloat()
{
	float a;
	cin>> a;
	return a;
}






class Admin 
{
	string Username;
	string Password;
	
	public: 
	Admin()
	{
		
	}
	Admin(string x,string y)
	{
		Username=x;
		Password=y;
	}	
	void Set_Name(string x)
	{
		Username=x;
				}
	void Set_Password(string x)
	{
		Password=x;
					}
	string getPassword()
	{
		return Password;
	}
	string getName()
	{
		return Username;
	}
	
	void printDetail() 
	{
		string fname;
		string lname;
		string mname;
		string nic,tempnic;
		string phoneNumber;
		int age,ban;
		string current_adress;
		string Password, reason;
	
		ifstream EditBan("RealEstate.txt", ios::in);
		
			while(EditBan >> nic >> fname >> mname >> lname >> phoneNumber >>  current_adress >> Password >> ban >> reason)
			{
				cout << nic << "\t" << fname << "\t" << mname << "\t" << lname << "\t" << phoneNumber << "\t"<< current_adress << "\t"<< Password <<  "\t" << ban << endl;	
			}
		
	}
	
	void BanUser() 
	{
		string fname;
		string lname;
		string mname;
		string nic,tempnic;
		string phoneNumber;
		int age,ban;
		string current_adress;
		string Password,reason;
		
		ofstream Edittemp("temp.txt", ios::out);
		ifstream EditBan("RealEstate.txt", ios::in);
		cout << "Enter user NIC to ban";
		cin >> tempnic;
		
			while(EditBan >> nic >> fname >> mname >> lname >> phoneNumber >>  current_adress >> Password >> ban >> reason)
			{
				if(nic==tempnic)
				{
					cout << "User found";
					cout << "first name" << fname << endl << "Enter 2 to ban this account or 1 to unban:";
					cin >> ban;
					while(ban>=2 && ban <=1) 
					{
						cout << "Invalid entry !" << endl << "please enter either 1 or 2:";
						cin >> ban;
						if(ban==2)
						{
							cout << "Reason for ban:" << endl;
							cin >> reason;
							cout << "User " << nic << " has been banned" << endl;
						}
						else
						{
							cout << "User " << nic << " has been unbanned" << endl;
						}
					}
					
					Edittemp << nic << "\t" << fname <<"\t"<< mname <<"\t" << lname << "\t" << phoneNumber << "\t" <<  current_adress << "\t"<< Password <<"\t"<< ban << "\t" << reason << "\n";
						
				}
				else
				{
				Edittemp << nic << "\t" << fname <<"\t"<< mname <<"\t" << lname << "\t" << phoneNumber << "\t" <<  current_adress << "\t"<< Password <<"\t"<< ban << "\t" << reason << "\n";
				}
			}
			
			EditBan.close();
			Edittemp.close();
			
			 ofstream editB("RealEstate.txt" , ios::out);
		     ifstream edittemp("temp.txt" , ios::in);
		     while(edittemp >> nic >> fname >> mname >> lname >> phoneNumber >>  current_adress >> Password >> ban >> reason)
		     {
		     	editB << nic << "\t" << fname <<"\t"<< mname <<"\t" << lname << "\t" << phoneNumber << "\t" <<  current_adress << "\t"<< Password <<"\t"<< ban << "\t" << reason << "\n";

			 }
	}
	
	void Deleteadd()
		{
			int option;
			string tempnic;
			
			
			cout << "What would you like to delete" << endl;
			cout << "1. a house "<< endl;
			cout << "2. an Apartment "<< endl;
			cout << "3. a plot" << endl;
			cout << "Enter option: ";
			cin >> option;
			
			
			string fname;
			string nic;
			string phoneNumber;		
			string address;
			int yearsOwned;
			double price;
			int type;
			string city;
			
			cout << "Enter NIC of the account whose add you wish to delete:" << endl;
			cin >> tempnic;
			
			if(option == 1)
			{
			int garage,floors, totalrooms;
			string adress_check;	
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditH("temp.txt", ios::out);
			ifstream OpenH("property.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City"<< "\t" << "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t" << "Garage" << "\t" << "Total-Rooms"<< endl;
			while(OpenH>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
				if(address == adress_check && nic == tempnic)
				{
				cout << nic << setw(15) << fname << setw(15)<< city<< setw(15) << phoneNumber << setw(15) << type <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << floors << setw(10) << garage << setw(10) << totalrooms<< endl;
							cout << "Deleting";
				//	cout << "Please enter the new price: ";
				//	cin >>  price;
					
				//	EditH << nic << "\t"<< fname << "\t" << phoneNumber << "\t"<<type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<floors << "\t" << garage << "\t" << totalrooms << endl;
				}
				else
				{
					EditH << nic << "\t"<< fname << "\t" << phoneNumber <<"\t"<< city<< "\t" <<  type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<floors << "\t" << garage << "\t" << totalrooms << endl;
				}	
			}
			OpenH.close();
			EditH.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceH("property.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms)
			{
					ReplaceH << nic << "\t"<< fname << "\t" << phoneNumber <<"\t"<< city << "\t"<<type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<floors << "\t" << garage << "\t" << totalrooms << endl;
			}
			cout << "Done..."<< endl;
			ReplaceH.close();
			}
			
			if(option == 2)
			{
		
			int FloorNum;
			int RoomNo;
					
			string adress_check;
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditA("temp.txt", ios::out);
			ifstream OpenA("propertyA.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Numbrer" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				if(address == adress_check && nic == tempnic)
				{
				cout << nic << setw(15) << fname << setw(15) << phoneNumber << setw(15) <<city <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << FloorNum << setw(20) << RoomNo << endl;
				
					}
				else
				{
					EditA << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<FloorNum << "\t" << RoomNo << endl;
				}	
			}
			OpenA.close();
			EditA.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceA("propertyA.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> FloorNum >> RoomNo )
			{
					ReplaceA << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" << FloorNum << "\t" << RoomNo << endl;
			}
			cout << "Done..."<< endl;
			ReplaceA.close();
			}
			
			if(option==3)
			{
				float size;
				
							
			string adress_check;
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditL("temp.txt", ios::out);
			ifstream OpenL("propertyL.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			while(OpenL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)
			{
				if(address == adress_check && nic == tempnic)
				{
				cout << nic << setw(15) << fname << setw(15) << phoneNumber << setw(15) <<city <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << size <<endl;
				}
				else
				{
					EditL << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city <<  "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<size << endl;
				}	
			}
			OpenL.close();
			EditL.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceL("propertyL.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >>  address >> price >> yearsOwned >> size )
			{
					ReplaceL << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" << size << endl;
			}
			cout << "Done..."<< endl;
			ReplaceL.close();
				
			}	
	}																																																																										
};


void adminOptions(Admin b);






class user 
{
	private:                
		string fname;
		string lname;
		string mname;
		string nic;
		string phoneNumber;
		string current_adress;
		string Password,reason;
		int ban;
	public:
		/*void input_fname()
		{	string i;
		
			cout << "Enter First name: ";
			cin >> i;
			set_fname(i);		
		}*/
		void login(string password, string Cnic)
			{
				ifstream login("RealEstate.txt", ios::in);
	
			while(login >> nic >> fname >> mname >> lname >> phoneNumber >>  current_adress >> Password >> ban >> reason)
			{
				if(Password == password && nic == Cnic)
				{
					if(ban==1)
					{
					    cout << "Login SucessFull \n";
					    //menuOf_Seller_Or_Register(password, Cnic);
					    //option =2;
					    break;
				    }
					else
					{
						cout << "You are banned from the website for:" << reason << endl << "To appeal your ban please contact the administrator" << endl;
					}  
				}
			}
			}
		
	friend	void UserRegesteration();
		
		void set_fname(string i)
		{
			fname= i;
		}
		
		/*void input_lname()
		{
			string i;
			cout << "Enter Last name: ";
			cin >> i;
			set_lname(i);
		}*/
		void set_lname(string i)
		{
			lname= i;
		}
		
		/*void input_mname()
		{
			string i;
			cout << "Enter Middle name: ";
			cin>> i;
			set_mname(i);
		}*/
		
		void set_mname(string i)
		{
			mname= i;
		}
		
		/*void input_NIC()
		{
			int i;
			cout << "Enter your Citizen Number/Passport Number: ";
			cin >> i;
			set_NIC(i);
		}*/
		
		void set_NIC(string i)
		{
			nic= i;
		}
		
		/*void Input_PhoneNumber()
		{
			int i;
			cout<< "Enter your phone number: ";
			cin >> i;
			set_PhoneNumber(i);
		}*/
		
		void set_PhoneNumber(string i)
		{
			phoneNumber=i;
		}
		
		/*void input_age()
		{
			int i;
			cout << "Enter your age: ";
			cin >> i;
			set_age(i);
		}*/
		
	//	void set_age(int i)
	//	{
	//		age=i;
	//	}
		
		/*void input_adress()
		{
			string i;
			cout << "Enter your current adress use \"_\"(undescore) instead of space: ";
			cin>> i;
			set_currentAress(i);
		}*/
		
		void set_currentAress(string i)
		{
			current_adress=i;
		}
		
		string get_fname(void)
		{
			return fname;
		}
		
		string get_lname(void)
		{
			return lname;
		}
		
		
		
		string get_mname(void)
		{
			return mname;
		}
		
		string get_nic(void)
		{
			return nic;
		}
		
		string get_phone_Number(void)
		{
			return phoneNumber;
		}

		//int get_age(void)
		//{
	//		return age;
	//	}
		
		string get_current_Adress(void)
		{
			return current_adress;
		}
		
		void set_password(string i)
		{
			Password = i;
		}
		
		string get_password()
		{
			return Password;
		}
		
		void set_ban(int a)
		{
			ban=a;
		}
		
		int get_ban()
		{
			return ban;
		}
		
		void set_reason(string i)
		{
			reason =i;
		}
		
		string get_reason()
		{
			return reason;
		}
		
		
		virtual void setrate(int x)
		{
			
			ofstream rate1("rateuser.txt",ios::app);
			rate1<<x<<"\t";
		}
		
		
		virtual	void inputrate()
		{
			int rate;
			ofstream rate1("rateuser.txt",ios::app);
	
			cout<<"Enter Rating :";
			cin>>rate;
			rate1<<rate<<"\t";
			rate1.close();
		}
		
		
		virtual	void outrate()
		{
			int rate;
			int temprate;
			int sum=0;
			int counter=0;
			float avg;
			ifstream rate2("rateuser.txt",ios::in);
	
			while(rate2>>temprate)
			{
				counter++;
		
				cout<<temprate<<"\n";
				sum-=-temprate;
			}
			avg=sum/counter;
			cout<<"Rating Of Buyer Is"<<avg;
	
			rate2.close();
		}
		
		
	void printdetails()
	{
		string fname;
		string lname;
		string mname;
		string nic,tempnic;
		string phoneNumber;
		int age,ban;
		string current_adress;
		string Password, reason;
	
		ifstream EditBan("RealEstate.txt", ios::in);
		cout<<"Cinic"<<"\t"<<"F Name"<<"\t"<<"M Name"<<"\t"<<"L Name"<<"\t"<<"Contact"<<"\t"<<"Address"<<endl;
			while(EditBan >> nic >> fname >> mname >> lname >> phoneNumber >>  current_adress >> Password >> ban >> reason)
			{
				if(nic==get_nic())
				
				
				cout << nic << "\t" << fname << "\t" << mname << "\t" << lname << "\t" << phoneNumber << "\t"<< current_adress<<endl;	
			}
		
		}	
		
		
};


void UserRegesteration(){
	
	user ap;
	loader("Loading Please Wait!");
	system("cls");	 
printf("#--------------------------------------------------------------------------#\n");	
printf("#                   Real Estate Property Managemen                         #\n");
printf("#                                                                          #\n");
printf("#                     You have chose to Regester                           #\n");	
printf("#                                                                          #\n");
printf("#                  Please provide us with your details                     #\n");
printf("#--------------------------------------------------------------------------#\n");

ofstream outfile;//used for file
outfile.open("RealEstate.txt", ios::app);//will store evetry data we want after it

printf("Enter your Citizen Number/Passport Number: ");
ap.set_NIC(inputstring()); //a.input_NIC();
checkcnic(ap.get_nic());
outfile << ap.get_nic() << "\t"; //will store data and leave 
printf("..................................................................\n");

printf("Enter your First Name:");
ap.set_fname(inputstring());
outfile << ap.get_fname() << "\t";
printf("..................................................................\n");

printf("Enter your Middle Name:");
ap.set_mname(inputstring());
outfile << ap.get_mname() << "\t";
printf("..................................................................\n");

printf("Enter your Last name:");
ap.set_lname(inputstring());
outfile << ap.get_lname() << "\t";
printf("..................................................................\n");

printf("Enter your phone number:");
ap.set_PhoneNumber(inputstring());
outfile << ap.get_phone_Number() << "\t";
printf("..................................................................\n");

printf("Enter your current adress use \"_\"(undescore) instead of space:");
ap.set_currentAress(inputstring());
outfile << ap.get_current_Adress() << "\t";
printf("..................................................................\n");
ap.set_reason("Not_Ban");
ap.set_ban(1) ;
printf("Enter your Password: ");
ap.set_password(inputstring());
outfile << ap.get_password() << "\t" << ap.get_ban() <<"\t"<< ap.get_reason()<< "\t\n";

outfile.close();
//ofstream reg("UserLogin.txt", ios::app);//will only register information  entered before it 
//reg<<data<<' '<<Password<<endl;// we have clearified the things to be regestered
} 








class property 
{
	protected:
		string city;
		string address;
		int yearsOwned;
		double price;
		int type; 
	public:
		property()
		{
			
		}
		
		property(string address,int yearsOwned,double price,int type)
		{
			this->address= address;
			this->yearsOwned= yearsOwned;
			this->price= price;
			this->type= type;
		}
		
	    void setAddress(string a)
	    {
	    	address=a;
		}
		void setYearsOwned(int a)
		{
			yearsOwned=a;
		}
		void setPrice(double a)
		{
			price=a;
		}
		void setType(int b)
		{
			type=b;
		}
		
		void setCity(string x)
		{
			city=x;	
		}
		
		string getCity()
		{
			return city;
		}
		
		string getAddress(){
			return address;
		}
		int getYearsOwned(){
			return yearsOwned;
		}
		double getPrice(){
			return price;
		}
		int getType(){
			return type;
		}
};









class Appartment: public property 
{
	int FloorNum;
	int RoomNo;
//	int number_of_room;
	public:
		
		
	Appartment(string w,int a,double p,int r): property(w, a, p, r)
	{
		//FloorNum=0;
		//RoomNo=0;
	}

	
	Appartment( string w,int a,double p,int r,int x,int y) : property(w,a,p,r), FloorNum(x), RoomNo(y)
	{
	}
	
	Appartment()
	{
		
	}
	
		
	
	void Set_FloorNum(int x)
	{
		FloorNum=x;
	}
	void Set_RoomNo(int x)
	{
		RoomNo=x;
	}
	int getFloorNum()
	{
		return FloorNum;
	}
	int getRoomNum()
	{
		return RoomNo;
	}
};







class Land : public property 
{
	float size;
	string zone; //commercial or residential
	public:
		void setSize(float a)
		{
			size=a;
		}
		void setZone(string a)
		{
			zone=a;
		}
		float getSize(){
			return size;
		}
		string getZone(){
			return zone;
		}
};






class House : public property 
{	
	int garage,floors, totalrooms;
	public:
		void setTotalRooms(int a)
		{
			totalrooms=a;
		}
	//	void setBathRooms(int b)
	//	{
	//		bathroom=b;
	//	}
	//	void setBedRoom(int c)
	//	{
	//		bedroom=c;
	//	}
		void setGarage(int d)
		{
			garage=d;
		}
		void setFloors(int e)
		{
			floors=e;
		}
	
		int get_garage()
		{
			return garage;
		}
		
		int get_floor()
		{
			return floors;
		}
		
		int get_totalrooms()
		{
			return totalrooms;
		}
};






class seller: public user 
{
	private:
		
		
	public:
	//		property a;
		
		void printdetails()
		{
			user::printdetails();
		}
		
		
		
		void sell_Property()
		{
			int a;
			int option;
			cout << "What would you like to sell" << endl;
			cout << "1. a house "<< endl;
			cout << "2. an Apartment "<< endl;
			cout << "3. a plot" << endl;
			//cout<<"4.Details";
			cout << "Enter option: ";
			cin >> option;
			
			
			if(option==1)
			{
			House h;
			string x;
			cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
			a=inputint();
			if(a==1 || a==2)
			{
			h.setType(a);
			}
			else
			{
			 while(a<1 || a>2)
			 {
				cout << "Please try again...\n";
				cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
				a= inputint();
				h.setType(a); 	
				}		
			}	
			cout<<"Enter the city where the property is located: ";
			h.setCity(inputstring());
			cout<<"Enter the Adress of the property: ";
			cin>>x;
			checkaddress(x);
			h.setAddress(x);
			cout<<"Enter the price: ";
			h.setPrice(inputdouble());
			cout<<"Input the number of floors: ";
			h.setFloors(inputint());
			cout<<"Enter the number of the rooms: ";
			h.setTotalRooms(inputint());
			cout<<"Enter the number of the garage: ";
			h.setGarage(inputint());
			cout<<"how old is the property: ";
			h.setYearsOwned(inputint());
			
			ofstream RegisterH("property.txt", ios::app);
			
			if(!RegisterH)
			{
				cerr << "File could not be opend "<< endl;
				exit(1);
			}
			
			RegisterH << user::get_nic()<< "\t" <<user::get_fname() << "\t" <<user::get_phone_Number() << "\t" << h.getCity() << "\t" <<h.getType() <<"\t" << h.getAddress() << "\t" << h.getPrice() << "\t" << h.getYearsOwned() << "\t"  << h.get_floor() << "\t" << h.get_garage() << "\t" << h.get_totalrooms() << endl;
			
			RegisterH.close();
		//	VIEW_AS_Seller(user::get_password(), user::get_nic());
			
			}
			if(option==2)
			{
				Appartment A;
				string x;
					
			cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
			a=inputint();
			if(a==1 || a==2)
			{
			A.setType(a);
			}
			else
			{
			 while(a<1 || a>2)
			 {
				cout << "Please try again...\n";
				cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
				a= inputint();
				A.setType(a); 	
				}		
			}	
			cout<<"Enter the city where the property is located: ";
			A.setCity(inputstring());
			cout<<"Enter the Adress of the property: ";
			cin>>x;
			checkaddress(x);
			A.setAddress(x);
			cout<<"Enter the price: ";
			A.setPrice(inputdouble());
			cout<<"how old is the property: ";
			A.setYearsOwned(inputint());
			cout<<"Input the floor on which the property is located: ";
			A.Set_FloorNum(inputint());
			cout<<"Input the number of the rooms: ";
			A.Set_RoomNo(inputint());
			ofstream RegisterA("propertyA.txt", ios::app);
			
			if(!RegisterA)
			{
				cerr << "File could not be opend "<< endl;
				exit(1);
			}
			
			RegisterA << user::get_nic()<< "\t" <<user::get_fname() << "\t" <<user::get_phone_Number() << "\t" << A.getCity() << "\t" << A.getType() <<"\t" << A.getAddress() << "\t" << A.getPrice() << "\t" << A.getYearsOwned() << "\t"  << A.getFloorNum() << "\t" << A.getRoomNum() << endl;
			
			RegisterA.close();		
			}
			
			if(option ==3)
			{
				Land A;
				string x;	
			cout<<"Enter the city where the property is located: ";
			A.setCity(inputstring());
			cout<<"Enter the Adress of the property: ";
			cin>>x;
			checkaddress(x);
			A.setAddress(x);
			cout<<"Enter the price: ";
			A.setPrice(inputdouble());
			cout<<"how old is the property: ";
			A.setYearsOwned(inputint());
			cout<<"Input the size of land: ";
			A.setSize(inputfloat());
			ofstream RegisterAL("propertyL.txt", ios::app);
			
			if(!RegisterAL)
			{
				cerr << "File could not be opend "<< endl;
				exit(1);
			}
			
			RegisterAL << user::get_nic()<< "\t" <<user::get_fname() << "\t" <<user::get_phone_Number() << "\t" << A.getCity() <<"\t" << A.getAddress() << "\t" << A.getPrice() << "\t" << A.getYearsOwned() << "\t"  << A.getSize() << endl;
			
			RegisterAL.close();	
			}
			
			
		}
	
	void edit_property()
		{
			int option;
			cout << "What would you like to edit" << endl;
			cout << "1. a house "<< endl;
			cout << "2. an Apartment "<< endl;
			cout << "3. a plot" << endl;
			cout << "Enter option: ";
			cin >> option;
			
			
			
			string fname;
			string nic;
			string phoneNumber;		
			string address;
			int yearsOwned;
			double price;
			int type;
			string city;
			
			if(option == 1)
			{
			int garage, floors, totalrooms;
			
			string adress_check;
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditH("temp.txt", ios::out);
			ifstream OpenH("property.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City"<< "\t" << "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t" << "Garage" << "\t" << "Total-Rooms"<< endl;
			while(OpenH>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
				if(address == adress_check && nic == user::get_nic())
				{
				cout << nic << setw(15) << fname << setw(15)<< city<< setw(15) << phoneNumber << setw(15) << type <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << floors << setw(10) << garage << setw(10) << totalrooms<< endl;
					int optionE=0;
					cout<< "1=YES\n";
					cout<< "2=NO\n";
					cout<< "Would you like to change the price: ";
					cin>> optionE;
					
					if(optionE==1)
					{
					cout << "Please enter the new price: ";
					cin >>  price;
					optionE=0;
					}
					
					cout<< "Would you like to enter the new adress: ";
					cin>> optionE;
					if(optionE==1)
					{
					cout << "Please enter the new adress: ";
					cin >>  address;
					optionE=0;
					}
					
					
					cout<< "Would you like to change the city: ";
					cin>>optionE;
					if(optionE==1)
					{
					cout << "Please enter the new location: ";
					cin >>  city;
					optionE=0;
					}
					
					cout<< "Would you like to change the type: ";
					cin>>optionE;
					if(optionE==1)
					{
					int a;			
					cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
					a=inputint();
					if(a==1 || a==2)
					{
					type=a;
					}
					else
					{
					 while(a<1 || a>2)
					{
						cout << "Please try again...\n";
						cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
						a= type;
							
					}		
					}	
					optionE=0;
					}
					
					
					
					EditH << nic << "\t"<< fname << "\t" << phoneNumber <<"\t"<< city<< "\t" << type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<floors << "\t" << garage << "\t" << totalrooms << endl;
				}
				else
				{
						EditH << nic << "\t"<< fname << "\t" << phoneNumber <<"\t"<< city<< "\t" <<  type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<floors << "\t" << garage << "\t" << totalrooms << endl;
				}	
			}
			OpenH.close();
			EditH.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceH("property.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms)
			{
					ReplaceH << nic << "\t"<< fname << "\t" << phoneNumber <<"\t"<< city << "\t"<<type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<floors << "\t" << garage << "\t" << totalrooms << endl;
			}
			cout << "Done..."<< endl;
			ReplaceH.close();
			//close OpenH.close();
			}
			
			if(option == 2)
			{
			
			int FloorNum;
			int RoomNo;
					
			string adress_check;
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditA("temp.txt", ios::out);
			ifstream OpenA("propertyA.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t"<< "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Numbrer" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				if(address == adress_check && nic == user::get_nic())
				{
				cout << nic << setw(15) << fname << setw(15) << phoneNumber << setw(15) <<city <<setw(15) <<type <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << FloorNum << setw(20) << RoomNo << endl;
				int optionE=0;
				
					cout<< "1=YES\n";
					cout<< "2=NO\n";
					cout<< "Would you like to change the price: ";
					cin>> optionE;
					
					if(optionE==1)
					{
					cout << "Please enter the new price: ";
					cin >>  price;
					optionE=0;
					}
					
					cout<< "Would you like to enter the new adress: ";
					cin>> optionE;
					if(optionE==1)
					{
					cout << "Please enter the new adress: ";
					cin >>  address;
					optionE=0;
					}
					
					
					cout<< "Would you like to change the city: ";
					cin>>optionE;
					if(optionE==1)
					{
					cout << "Please enter the new location: ";
					cin >>  city;
					optionE=0;
					}
					
					cout<< "Would you like to change the type: ";
					cin>>optionE;
					if(optionE==1)
					{
					int a;			
					cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
					a=inputint();
					if(a==1 || a==2)
					{
					type=a;
					}
					else
					{
					 while(a<1 || a>2)
					{
						cout << "Please try again...\n";
						cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
						a= type;
							
					}		
					}	
					optionE=0;
					}
					
					
					EditA << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t"<< type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<FloorNum << "\t" << RoomNo << endl;
				}
				else
				{
					EditA << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t"<< type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<FloorNum << "\t" << RoomNo << endl;
				}	
			}
			OpenA.close();
			EditA.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceA("propertyA.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> FloorNum >> RoomNo )
			{
					ReplaceA << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t"<< type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" << FloorNum << "\t" << RoomNo << endl;
			}
			cout << "Done..."<< endl;
			ReplaceA.close();
			}			
		
			if(option==3)
			{
				float size;
				
							
			string adress_check;
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditAL("temp.txt", ios::out);
			ifstream OpenAL("propertyL.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			while(OpenAL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)
			{
				if(address == adress_check && nic == user::get_nic() )
				{
				cout << nic << setw(15) << fname << setw(15) << phoneNumber << setw(15) <<city  <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << size <<endl;
				
					int optionE=0;
					cout<< "1=YES\n";
					cout<< "2=NO\n";
					cout<< "Would you like to change the price: ";
					cin>> optionE;
					
					if(optionE==1)
					{
					cout << "Please enter the new price: ";
					cin >>  price;
					optionE=0;
					}
					
					cout<< "Would you like to enter the new adress: ";
					cin>> optionE;
					if(optionE==1)
					{
					cout << "Please enter the new adress: ";
					cin >>  address;
					optionE=0;
					}
					
					
					cout<< "Would you like to change the city: ";
					cin>>optionE;
					if(optionE==1)
					{
					cout << "Please enter the new location: ";
					cin >>  city;
					optionE=0;
					}
					
				/*	cout<< "Would you like to change the type: ";
					cin>>optionE;
					if(optionE==1)
					{
					int a;			
					cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
					a=inputint();
					if(a==1 || a==2)
					{
					type=a;
					}
					else
					{
					 while(a<1 || a>2)
					{
						cout << "Please try again...\n";
						cout<< "Press 1 for rent \n" << "Press 2 for permenent\n";
						a= type;
							
					}		
					}	
					optionE=0;
					}
				*/	
					
					EditAL << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<size << endl;
				}
				else
				{
					EditAL << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<size << endl;
				}	
			}
			OpenAL.close();
			EditAL.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceAL("propertyL.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size )
			{
					ReplaceAL << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" << size << endl;
			}
			cout << "Done..."<< endl;
			ReplaceAL.close();
				
			}
			
		}
		
		
		void deleteadd()
		{
			int option;
			cout << "What would you like to delete" << endl;
			cout << "1. a house "<< endl;
			cout << "2. an Apartment "<< endl;
			cout << "3. a plot" << endl;
			cout << "Enter option: ";
			cin >> option;
			
			
			string fname;
			string nic;
			string phoneNumber;		
			string address;
			int yearsOwned;
			double price;
			int type;
			string city;
			
			if(option == 1)
			{
			int garage,floors, totalrooms;
			string adress_check;	
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditH("temp.txt", ios::out);
			ifstream OpenH("property.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City"<< "\t" << "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t" << "Garage" << "\t" << "Total-Rooms"<< endl;
			while(OpenH>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
				if(address == adress_check && nic == user::get_nic())
				{
				cout << nic << setw(15) << fname << setw(15)<< city<< setw(15) << phoneNumber << setw(15) << type <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << floors << setw(10) << garage << setw(10) << totalrooms<< endl;
							cout << "Deleting";
				}
				else
				{
					EditH << nic << "\t"<< fname << "\t" << phoneNumber <<"\t"<< city<< "\t" <<  type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<floors << "\t" << garage << "\t" << totalrooms << endl;
				}	
			}
			OpenH.close();
			EditH.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceH("property.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms)
			{
					ReplaceH << nic << "\t"<< fname << "\t" << phoneNumber <<"\t"<< city << "\t"<<type << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<floors << "\t" << garage << "\t" << totalrooms << endl;
			}
			cout << "Done..."<< endl;
			ReplaceH.close();
			}
			
			if(option == 2)
			{
		
			int FloorNum;
			int RoomNo;
					
			string adress_check;
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditA("temp.txt", ios::out);
			ifstream OpenA("propertyA.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Numbrer" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				if(address == adress_check && nic == user::get_nic())
				{
				cout << nic << setw(15) << fname << setw(15) << phoneNumber << setw(15) <<city <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << FloorNum << setw(20) << RoomNo << endl;
				
					}
				else
				{
					EditA << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<FloorNum << "\t" << RoomNo << endl;
				}	
			}
			OpenA.close();
			EditA.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceA("propertyA.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> FloorNum >> RoomNo )
			{
					ReplaceA << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" << FloorNum << "\t" << RoomNo << endl;
			}
			cout << "Done..."<< endl;
			ReplaceA.close();
			}
			
			if(option==3)
			{
				float size;
				
							
			string adress_check;
			cout << "Enter the property adress: ";
			cin >>  adress_check;
			
			ofstream EditL("temp.txt", ios::out);
			ifstream OpenL("propertyL.txt", ios::in);
	
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			while(OpenL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)
			{
				if(address == adress_check && nic == user::get_nic())
				{
				cout << nic << setw(15) << fname << setw(15) << phoneNumber << setw(15) <<city <<setw(25)<< address << setw(10) << price << setw(15) << yearsOwned << setw(10)  << size <<endl;
				}
				else
				{
					EditL << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city <<  "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" <<size << endl;
				}	
			}
			OpenL.close();
			EditL.close();
			
			ifstream ReadTemp("temp.txt", ios::in);
			ofstream ReplaceL("propertyL.txt", ios::out);
			while(ReadTemp>> nic >> fname>> phoneNumber >> city >>  address >> price >> yearsOwned >> size )
			{
					ReplaceL << nic << "\t"<< fname << "\t" << phoneNumber  <<"\t"<< city << "\t" << address << "\t"<< price  << "\t"<<yearsOwned << "\t" << size << endl;
			}
			cout << "Done..."<< endl;
			ReplaceL.close();
				
			}
		}
		
		void view_Your_Add()
		{
					
			string fname;
			string nic;
			string phoneNumber;		
			int garage,floors, totalrooms;
			string address;
			int yearsOwned;
			double price;
			int type; 
			int FloorNum;
			float size;
			int RoomNo;
			string city;
			ifstream OpenH("property.txt", ios::in);
			ifstream OpenA("propertyA.txt", ios::in);
			ifstream OpenL("propertyL.txt", ios::in);	
			cout << endl << "House" << endl;
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t"<< "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t  " << "Garage" << "\t" << "Total-Rooms"<< endl;
			while(OpenH>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
				if(nic == user::get_nic())
				{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) <<type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << floors << setw(8) << garage << setw(10) << totalrooms<< endl;
				}
			}
			
			cout << endl << "Appartment" << endl;
					cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t" <<"Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Number" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				if(nic == user::get_nic())
				{
				cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) << type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << FloorNum << setw(20) << RoomNo << endl;
				}
			}
			
			cout << endl << "Land" << endl;
			cout << "N.I.C" << setw(15) << "First-Name" << setw(16) << "Phone-Number" << "\t" << "City" <<"\t      " << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			
			while(OpenL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)
			{
				if(nic == user::get_nic())
				{
				cout << nic << setw(15) << fname << setw(20) << phoneNumber << setw(10) <<city  <<setw(15)<< address << setw(12) << price << setw(15) << yearsOwned << setw(12)  << size <<endl;
				}
			}
		 OpenH.close();
		 OpenA.close();
		 OpenL.close();
		}
		/*void set_password(string i)
		{
			user::sePassword = i;
		}
		
		string get_password()
		{
			return Password;
		}*/
		//functions such as add an ad,edit it etc defined here
		
	//		void setrate(int x)
//		{
//			ofstream rate1("rateseller.txt",ios::app);
//			rate1<<x<<"\t";
//		}
//		void inputrate()
//		{
//			int rate;
//		ofstream rate1("rateseller.txt",ios::app);
//	
//		cout<<"Enter Rating :";
//		cin>>rate;
//		rate1<<rate<<"\t";
//		rate1.close();
//		}
		void outrate()
		{
		//	int cnic1;
		//	cout<<"Enter Cnic of seller :";
		//	cin>>cnic1;
			int rate;
			string tempcnic;
			int temprate;
			int sum=0;
			int counter=0;
			float avg;
			ifstream rate2("ratebuyer.txt",ios::in);
	
			while(rate2>>tempcnic>>temprate)
			{
				if(tempcnic==get_nic())
				{
				counter++;
				sum+=temprate;
				}
			}
			
			avg=sum/counter;
			loader("Loading...");
			system("cls");
			cout<<"Rating Of You Is :"<<avg<<endl;
			cout<<"\n";
		
			rate2.close();
		}
};







class buyer: public user 
{
	
		
		
	public:
		
		printdeatails()
		{
			user::printdetails();
		}
		void view_Property()
		{ //	House h;
			system("cls");
				
			string fname;
			string nic;
			string phoneNumber;		
			int garage,floors, totalrooms;
			string address;
			int yearsOwned;
			double price;
			float size;
			int type; 
			int FloorNum;
			int RoomNo;
			string city;
			ifstream OpenH("property.txt", ios::in);
			ifstream OpenA("propertyA.txt", ios::in);
			ifstream OpenL("propertyL.txt", ios::in);
			cout << endl << "House" << endl;
			
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t"<< "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t  " << "Garage" << "\t" << "Total-Rooms"<< endl;
			while(OpenH>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) <<type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << floors << setw(8) << garage << setw(10) << totalrooms<< endl;
				
			}
			
			cout << endl << "Appartment" << endl;
					cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t" <<"Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Number" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				
				cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) << type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << FloorNum << setw(18) << RoomNo << endl;
				
			}
			
			cout << endl << "Land" << endl;
			cout << "N.I.C" << setw(15) << "First-Name" << setw(16) << "Phone-Number" << "\t" << "City" <<"\t      " << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			
			while(OpenL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)
			{
				cout << nic << setw(15) << fname << setw(20) << phoneNumber << setw(10) <<city  <<setw(15)<< address << setw(12) << price << setw(15) << yearsOwned << setw(12)  << size <<endl;
			}
		 OpenH.close();
		 OpenA.close();
		 OpenL.close();
		 cout << endl<< endl;
		}
		
void filter()
		{
	loader("Loading Please Wait!");
	system("cls");
				
			string fname;
			string nic;
			string phoneNumber;		
			int garage,floors, totalrooms;
			string address;
			int yearsOwned;
			double price;
			float size;
			int type; 
			int FloorNum;
			int RoomNo;
			string city;
			int choice;
			int opt;
			string tempcity;
			ifstream OpenH("property.txt", ios::in);
			ifstream OpenA("propertyA.txt", ios::in);
			ifstream OpenL("propertyL.txt", ios::in);
			
			cout<<"Select the option:"<<endl;
			cout<<"1.House"<<endl;
			cout<<"2.Appartment"<<endl;
			cout<<"3.Zameen"<<endl;
			cin>>opt;
			
			if(opt==1)
			{
			cout<<"\n1.City\n2.Price\n3.Years Owned"<<endl;
			cout<<"4.Garage\n5.Floor"<<endl;
			cout<<"\nEnter Your Choice:"<<endl;
			cin>>choice;
			
			if(choice==1)
			{
			
			
			cout<<"Enter Name Of City You Want To search:"<<endl;
			
			
			cin>>tempcity;
				
			cout << endl << "House" << endl;
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t"<< "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t  " << "Garage" << "\t" << "Total-Rooms"<< endl;	
			while(OpenH>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
			if(city==tempcity)
			{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) <<type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << floors << setw(8) << garage << setw(10) << totalrooms<< endl;
			}
			}
			
			}
			else if(choice==2)
			{
					double max;
					double min;
					cout<<"Enter Maximum Price:"<<endl;
					cin>>max;
					cout<<"Enter Minimum Price:"<<endl;
					cin>>min;
			
			cout << endl << "House" << endl;
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t"<< "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t  " << "Garage" << "\t" << "Total-Rooms"<< endl;		
			while(OpenH>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
				
					if(price<=max && price>=min)
					{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) <<type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << floors << setw(8) << garage << setw(10) << totalrooms<< endl;
					}
			}}
			else if(choice==3)
			{
				int tempyear;
		
				cout<<"Enter Year Owned:"<<endl;
				cin>>tempyear;		
			
			cout << endl << "House" << endl;
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t"<< "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t  " << "Garage" << "\t" << "Total-Rooms"<< endl;			
			while(OpenH>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
				
					if(yearsOwned==tempyear)
					{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) <<type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << floors << setw(8) << garage << setw(10) << totalrooms<< endl;
					}
			}
			}
			else if(choice==4)
			{
				int tempg;
			cout<<"Enter Number Of Garages:"<<endl;
				cin>>tempg;
				cout << endl << "House" << endl;
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t"<< "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t  " << "Garage" << "\t" << "Total-Rooms"<< endl;
				while(OpenH>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
				
					if(tempg==garage)
					{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) <<type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << floors << setw(8) << garage << setw(10) << totalrooms<< endl;
					}
			}
			}
				else if(choice==5)
		{
				int tempfloor;
				
				cout<<"Enter Number Of Floors:"<<endl;
				cin>>tempfloor;
				cout << endl << "House" << endl;
			cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" <<"\t"<< "Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floors" << "\t  " << "Garage" << "\t" << "Total-Rooms"<< endl;
			while(OpenH>> nic >> fname>> phoneNumber >> city >>type >> address >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
				
					if(tempfloor==floors)
					{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) <<type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << floors << setw(8) << garage << setw(10) << totalrooms<< endl;
					}
			}
				}
			}
			if(opt==2)
			{
			cout<<"\n1.City\n2.Price\n3.Years Owned"<<endl;
			cout<<"4.Size"<<endl;
			cout<<"\nEnter Your Choice:"<<endl;
			cin>>choice;
				if(choice==1)
			{
			
			
			cout<<"Enter Name Of City You Want To search:"<<endl;
			
			
			cin>>tempcity;
				
			cout << endl << "Appartment" << endl;
					cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t" <<"Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Number" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
			if(city==tempcity)
			{
			cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) << type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << FloorNum << setw(18) << RoomNo << endl;
			}
			}
			
			}
			else if(choice==2)
			{
					double max;
					double min;
					cout<<"Enter Maximum Price:"<<endl;
					cin>>max;
					cout<<"Enter Minimum Price:"<<endl;
					cin>>min;
				cout << endl << "Appartment" << endl;
					cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t" <<"Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Number" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				
					if(price<=max && price>=min)
					{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) << type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << FloorNum << setw(18) << RoomNo << endl;
					}
			}}
			else if(choice==3)
			{
				int tempyear;
		
				cout<<"Enter Year Owned:"<<endl;
				cin>>tempyear;		
			
			cout << endl << "Appartment" << endl;
					cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t" <<"Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Number" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				
					if(yearsOwned==tempyear)
					{
					cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) << type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << FloorNum << setw(18) << RoomNo << endl;
					}
			}
			}
			else if(choice==4)
			{
				int tempflr;
				
				cout<<"Enter Floor Number:"<<endl;
				cin>>tempflr;
				
				cout << endl << "Appartment" << endl;
					cout << "N.I.C" << "\t" << "First-Name" << "\t" << "Phone-Number" << "\t" << "City" << "\t" <<"Rent(1)/Purchase(2)" <<"\t" << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "Floor_Number" << "\t" << "Room_Number" << endl;
			while(OpenA>> nic >> fname>> phoneNumber >> city >> type >> address >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				if(tempflr==FloorNum)
				{
				cout << nic << setw(12) << fname << setw(22) << phoneNumber << setw(10) << city << setw(10) << type <<setw(25)<< address << setw(8) << price << setw(15) << yearsOwned << setw(15)  << FloorNum << setw(18) << RoomNo << endl;
				}
			}
					}}
	
	
	
	
	
		if(opt==3)
		{
			cout<<"\n1.City\n2.Price\n3.Years Owned"<<endl;
			cout<<"4.Size"<<endl;
			cout<<"\nEnter Your Choice:"<<endl;
			cin>>choice;
			
			if(choice==1)
			{
			
			
			cout<<"Enter Name Of City You Want To search:"<<endl;
			
			
			cin>>tempcity;
				
			cout << endl << "Land" << endl;
			cout << "N.I.C" << setw(15) << "First-Name" << setw(16) << "Phone-Number" << "\t" << "City" <<"\t      " << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			
			while(OpenL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)
			{
			if(city==tempcity)
			{
							cout << nic << setw(15) << fname << setw(20) << phoneNumber << setw(10) <<city  <<setw(15)<< address << setw(12) << price << setw(15) << yearsOwned << setw(12)  << size <<endl;
			}
			}
			
			}
			else if(choice==2)
			{
					double max;
					double min;
					cout<<"Enter Maximum Price:"<<endl;
					cin>>max;
					cout<<"Enter Minimum Price:"<<endl;
					cin>>min;
			
			cout << endl << "Land" << endl;
			cout << "N.I.C" << setw(15) << "First-Name" << setw(16) << "Phone-Number" << "\t" << "City" <<"\t      " << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			
			while(OpenL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)
			{
				
					if(price<=max && price>=min)
					{
					cout << nic << setw(15) << fname << setw(20) << phoneNumber << setw(10) <<city  <<setw(15)<< address << setw(12) << price << setw(15) << yearsOwned << setw(12)  << size <<endl;
					}
			}}
			else if(choice==3)
			{
				int tempyear;
		
				cout<<"Enter Year Owned:"<<endl;
				cin>>tempyear;		
			cout << endl << "Land" << endl;
			cout << "N.I.C" << setw(15) << "First-Name" << setw(16) << "Phone-Number" << "\t" << "City" <<"\t      " << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			
			while(OpenL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)
			{
				
					if(yearsOwned==tempyear)
					{
							cout << nic << setw(15) << fname << setw(20) << phoneNumber << setw(10) <<city  <<setw(15)<< address << setw(12) << price << setw(15) << yearsOwned << setw(12)  << size <<endl;
					}
			}
			}
			else if(choice==4)
			{
				int SIZE;
				cout<<"Enter Size Of Land:"<<endl;
				cin>>SIZE;
				
cout << endl << "Land" << endl;
			cout << "N.I.C" << setw(15) << "First-Name" << setw(16) << "Phone-Number" << "\t" << "City" <<"\t      " << "Address" << "\t    " << "Price" << "\t" << "Years-Owned" << "\t"  << "size" << endl;
			
			while(OpenL>> nic >> fname>> phoneNumber >> city >> address >> price >> yearsOwned >> size)			
			{	
					if(SIZE==size)
					{
							cout << nic << setw(15) << fname << setw(20) << phoneNumber << setw(10) <<city  <<setw(15)<< address << setw(12) << price << setw(15) << yearsOwned << setw(12)  << size <<endl;
					}
			}
			}
					}			
			

			
			
			}
			
			
		void setrate(int x)
		{
			ofstream rate1("ratebuyer.txt",ios::app);
			rate1<<x<<"\t";
		}
		
		
		void inputrate()
		{
		loader("Loading...");
		system("cls");
			int rate;
			double cnic1;
		ofstream rate1("ratebuyer.txt",ios::app);
	
		cout<<"Enter Rating :[1-5]";
	
		cin>>rate;
		cout<<"Enter Cnic:";
		cin>>cnic1;
		
	//	while(1)
		{
		
		if(rate<=5)
		{
		
		rate1<<cnic1<<"\t"<<rate<<"\n";
	//	break;
	}
//		else 
//		{
//			cout<<"Enter Again!";
//			cin>>rate;
//		}
		rate1.close();
		}}
		
		//{
//		void outrate()
//		{
//			int rate;
//	int temprate;
//	int sum=0;
//	int counter=0;
//	float avg;
//			ifstream rate2("ratebuyer.txt",ios::in);
//	
//	while(rate2>>temprate)
//	{
//		counter++;
//		sum-=-temprate;
//	}
//	avg=sum/counter;
//	cout<<"Rating Of Buyer Is"<<avg;
//	
//	rate2.close();
//		}
	/*void set_password(string i)
		{
			Password = i;
		}
		
		string get_password()
		{
			return Password;
		}*/
	//viewing functions defined here
};




int main()
{
	system("color b1");
	menu();
}





void login()  
{
	string password;
	string Cnic;
//	loader("Loading Please Wait!");
	system("cls");
	cout << "___________________"<< endl;
	cout << "----Real Estate----"<< endl;
	cout << "Enter Nic Number: "<< endl;
	cin  >> Cnic;
	cout << "Enter Password: "<< endl;
	cin  >> password; 

	
	ifstream login("RealEstate.txt", ios::in);
	
		string fname;
		string lname;
		string mname;
		string nic;
		string phoneNumber;
		int age;
		string current_adress;
		string Password,reason;
		int ban;
		int option =1;
	while(option==1)
	{
		if(option == 1)
		{
			//cout << "Check: ";
		while(login >> nic >> fname >> mname >> lname >> phoneNumber >>  current_adress >> Password >> ban >> reason)
		{
			//cout << "Check: ";
	//	cout << Password;
	//	cout << nic;
		
	//	while(!EOF);
		
			if(Password == password && nic == Cnic)
			{
				if(ban==1)
				{
				    cout << "Login SucessFull \n";
				    menuOf_Seller_Or_Register(password, Cnic);
			    	break;
			    }
			    else
			    {
			    	cout << "You are banned from the website for:" << reason << endl << "To appeal your ban please contact the administrator" << endl;
			    	exit(1);
				}
			}
			else if(nic == Cnic)
			{
				
				while(Password != password)
				{	
					cout << "Please enter the correct password: ";
					cin >> password;
				}
				if(password== Password)
				{
					if(ban==1)
				    {
				        cout << "Login SucessFull \n";
				        menuOf_Seller_Or_Register(password, Cnic);
			        	break;
			        }
			        else
			        {
			        	cout << "You are banned from the website for:" << reason << endl << "To appeal your ban please contact the administrator" << endl;
			    	    exit(1);
				    }
				}
			}
			
			/*else if(password == Password)
			{
				while(nic != Cnic)
				{
					cout << "Please enter the correct nic: ";
					cin >> Cnic;
				}
				if(nic== Cnic)
				{
					cout << "Login SucessFull \n";
					menuOf_Seller_Or_Register(password, Cnic);
					break;
				}	
			}*/
			else
			{
				cout << "No such account found Try to re-register: ";
				
			}
		}
	//	
			option = 2;
			login.close();
		}
		if(option = 2)
		{
		menu();
		}
		
	}
	
		
//	menuOf_Seller_Or_Register(password, Cnic);
}
COORD CursorPosition;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

void loader(string xyz)
{
    int i;
	system("cls");
	gotoXY(20,10);
	cout<<xyz<<endl;
	gotoXY(20,12);
	for (i=0;i<20;i++)
	{
		Sleep(20);
		printf("%c",219);
	}
}

void checkcnic(string cnic5)
{
	string fname;
		string lname;
		string mname;
		string nic,tempnic;
		string phoneNumber;
		int age,ban;
		string current_adress;
		string Password, reason;
		ifstream infile("RealEstate.txt",ios::in);
		 
		 while(infile >> nic >> fname >> mname >> lname >> phoneNumber >>  current_adress >> Password >> ban >> reason)
			{
				if(nic==cnic5)
				{
				cout<<"Already exits!";	
				getch();
				menu();}
			}
			
		
}




int menu()
{
	system("cls");
	
	int option=1;
	while(option == 1 || option ==2)
	{//loader("Loading Please Wait!");
	system("cls");
		
		
	cout << "___________________"<< endl;
	cout << "----Real Estate----"<< endl;
	cout << "1: Login\n";
	cout << "2: Register\n";
	cout << "3: EXIT\n";
	cin>> option;
	
	if(option==2)
	{
		
		seller a;
		UserRegesteration();
	}
	if(option==1)
	{
		login();
	}
	if(option == 3)
	{
		exit(1);
	}
	if(option ==432)
	{
		 view_As_Admin();	
	}	
}
}

void  view_As_Admin()
{
	Admin a;
	string username,password,tempuser,temppass;
	cout << "Login as admin" << endl;
	
	cout << "Enter username: "<< endl;
	cin  >> tempuser;
	cout << "Enter Password: "<< endl;
	cin  >> temppass; 
	
	ifstream login("Admininfo.txt",ios::in);
	while(login >> username >> password)
		{
			//cout << "Check: ";
	//	cout << Password;
	//	cout << nic;
		
	//	while(!EOF);
		
			if(password == temppass && username == tempuser)
			{
				cout << "Logged in as Administrator" << endl;
				adminOptions(a);
			}
			else if(username == tempuser )
			{
				
				while(temppass != password)
				{	
					cout << "Please enter the correct password: ";
					cin >> password;
				}
				if(password== temppass)
				{
					cout << "Logged in as Administrator" << endl;
					adminOptions(a);
					break;
				}
			}
			/*else if(password == Password)
			{
				while(nic != Cnic)
				{
					cout << "Please enter the correct nic: ";
					cin >> Cnic;
				}
				if(nic== Cnic)
				{
					cout << "Login SucessFull \n";
					menuOf_Seller_Or_Register(password, Cnic);
					break;
				}	
			}*/
			else
			{
				cout << "No such account found" << endl;
				
			}
	//a.printDetail();
}
}






void menuOf_Seller_Or_Register(string password, string Cnic)
{
	seller a;
	buyer b;
	int option=0;
	loader("Loading Please Wait!");
	system("cls");
	do{
	cout << "View as: "<< endl;
	cout << "1. Seller\n";
	cout << "2. Byer\n";
	cout << "3. Exit\n";
	cout << "Enter option: ";
	cin >> option;
	
	if(option ==1)
	{
		VIEW_AS_Seller(password, Cnic);
	}
	else if(option == 2)
	{
		VIEW_AS_Byer(password, Cnic);
	}
	}while(option != 3);
	
}









void VIEW_AS_Seller(string password, string Cnic) 
{
	seller a;
	a.login(password, Cnic);
//	cout <<a.get_lname();
	int option=0;
	loader("Loading Please Wait!");
	system("cls");
	do{
	cout << "1. To sell your property "<< endl;
	cout << "2. To Edit your Add "<< endl;
	cout << "3. To delete your add:" << endl;
	cout << "4. To view your add: "<< endl;
	cout<<"5.To view your Details"<<endl;
	cout<<"6.To view rating:"<<endl;
	
	cin>> option;
	if(option==1)
	{
		system("cls");
		a.sell_Property();
		cout<< endl<< endl;
	}
	if(option==2)
	{
		system("cls");
		a.edit_property();
		cout<< endl<< endl;
	}
	if(option == 3)
	{
		system("cls");
		a.deleteadd();	
		cout<< endl<< endl;
	}
	if(option == 4)
	{
		system("cls");
		a.view_Your_Add();
		cout<< endl<< endl;
	}
	if(option==6)
	{
		a.outrate();
	}
	if(option==5)
	{
	a.printdetails();
	}
	}while(option != 7);
	
//	if(option == 3)
//	{
//		menuOf_Seller_Or_Register(password, a.get_nic());
	//}
}







void VIEW_AS_Byer(string password, string Cnic)
{
	buyer a;
	a.login(password, Cnic);
	//cout<< "BYER"<< endl;
	int option;
	cout<< "Press 1 to view property: ";
	cout << "\nPress 2 to filter property: ";
	cout<<"\nPress 3 To view your Details\n";
	cout<<"Press 4 to Rate\n";
	cin >> option;
	if(option==4)
	{
		a.inputrate();
	}
	if(option==3)
		{
				a.printdetails();
		}
	if(option ==1 )
	{ 
	a.view_Property();
	}
	if(option==2)
	{
		a.filter();
		}	
}

void adminOptions(Admin b)
{
	int option;
	while(option!=4)
	{
		cout << "1-Press 1 to view user accounts" << endl << "2-Press 2 to ban an account" << endl << "3-Press 3 to delete an advertisement" << endl;
    cin >> option;
    system("cls");
    while(option<1 && option >3)
    {
    	cout << "Invalid selection. Enter a value from 1 or 2 or 3" << endl; 
    	cin >> option;
    	system("cls");
	}
    if(option==1)
    {
    	b.printDetail();
	}
	if(option==2)
	{
		b.BanUser();
	}
	if(option==3)
	{
		//cout << "Feature under development :)" << endl;
		b.Deleteadd();
	}
	}
	
}


void checkaddress(string x)
			{
				string adr;
				
			ifstream OpenH("property.txt",ios::in);
			ifstream OpenA("propertyA.txt",ios::in);
			ifstream OpenL("propertyL.txt",ios::in);
			string fname;
			string nic;
			string phoneNumber;		
			int garage,floors, totalrooms;
			int yearsOwned;
			double price;
			float size;
			int type; 
			int FloorNum;
			int RoomNo;
			string city;
		
				while(OpenH>> nic >> fname>> phoneNumber >> city >>type >> adr >> price >> yearsOwned >> floors >>garage >> totalrooms )
			{
					if(adr==x)
					{
					cout << "Already Exist"<<endl;
					getch();
					system("cls");
					menu();
					
					}//menu
			}
				while(OpenA>> nic >> fname>> phoneNumber >> city >> type >> adr >> price >> yearsOwned >> FloorNum >> RoomNo)
			{
				
				if(adr==x)
				{
				cout<<"Already Exist!"<<endl;
				getch();
					system("cls");
					menu();
				}//menu
			}
				while(OpenL>> nic >> fname>> phoneNumber >> city >> adr >> price >> yearsOwned >> size)
			{
				if(adr==x)
				{
			cout<<"Already Exit!"<<endl;
			getch();
					system("cls");
					menu();
			//menu
				}
			}
}
