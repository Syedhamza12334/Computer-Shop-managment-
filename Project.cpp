#include<iostream>//for input and output
#include<string>//for string use in code
using namespace std;
void stars(int);

class Desktop{
	public:
		void Recommend(int price)
		{
			if(price == 1)
			{
				cout<<"CPU - Intel Core i3-2120 Dual-Core 3.3GHz\n";
				cout<<"Memory - 250gb HDD\n";
				cout<<"GPU - Geforce GT 610 DDR3 1gb\n";
				cout<<"Ram - 4gb Stock Memory\n";
				cout<<"PSU - 265W";
			}
			else if(price==2)
			{
				cout<<"CPU - Intel Core i3-2120 Dual-Core 3.3GHz\n";
				cout<<"Memory - 500gb HDD OR 120gb SSD\n";
				cout<<"GPU - Geforce GT 610 DDR3 1gb\n";
				cout<<"Ram - 8gb Stock Memory\n";
				cout<<"PSU - 265W";
			}
			else if(price==3)
			{
				cout<<"CPU - Intel Core i5-3570 3.80GHz\n";
				cout<<"Memory - 500gb HDD OR 120gb SSD\n";
				cout<<"GPU - Geforce GTX 750Ti \n";
				cout<<"Ram - 8gb Stock Memory\n";
				cout<<"PSU - 400W";
			}
			else{
				cout<<"Sorry Option Not Available :(";
			}
			cout<<endl;
			system("pause");
			system("CLS");
		}
		
};

class parts{
	public:
		float price;
		string CpuName;
		char ch;
		bool MotherBoardAdded = false;
};

class Memory : public parts{
	private:
		int size;
	public : 
		bool isHdd = true;
		int HDsize;
		void MemoryType(string MemoryT)
		{
			if(MemoryT == "SSD")
			{
				cout<<"Please Confirm Your Desired Memory Size-\n(1)120gb, (2)128gb, (3)240gb, (4)256gb : ";cin>>size;
				switch(size)
				{
					case 1:
						price = 4400;
						HDsize=120;
						break;
					case 2:
						price = 4800;
						HDsize=128;
						break;
					case 3:
						price = 6100;
						HDsize=240;
						break;
					case 4:
						price = 6600;
						HDsize=256;
						break;
				}
				cout<<"Memory conformed Price : "<<price<<endl;
				isHdd=false;
			}
			else{
				
				cout<<"Please Confirm Your Desired Memory Size-\n(1)250gb, (2)500gb, (3)1tb, (4)2tb : ";cin>>size;
				switch(size)
				{
					case 1:
						price = 1250;
						HDsize=250;
						break;
					case 2:
						price = 6400;
						HDsize=500;
						break;
					case 3:
						price = 7200;
						HDsize=1000;
						break;
					case 4:
						price = 9850;
						HDsize=2000;
						break;
				}
				cout<<"Memory conformed Price : "<<price<<endl;
			}
		}
};

class Ram : public parts{
	private :
		int Rsize,Mp;
	public:
		int TRsize;
		void callRam()
		{
			cout<<"Choose From Following Option : \n";
			cout<<"(1) 2gb, (2) 4gb, (3) 8gb, (4) 16gb\n";
			cin>>Rsize;
			cout<<"Enter Number Of Sticks : ";cin>>Mp;cout<<endl;
			if(Rsize == 1)
			{
				TRsize = 2*Mp;				
			}
			else if(Rsize == 2)
			{
				TRsize = 4*Mp;;
			}
			else if(Rsize == 3)
			{
				TRsize = 8*Mp;;
			}
			else if(Rsize == 4)
			{
				TRsize = 16*Mp;
			}
			price = 800*TRsize;
			cout<<"Ram Confirmed Price = "<<price<<"\tMemory = "<<TRsize<<"GB\n";
			
		}
	
};

class CPU : public parts{
	private:
		int ch,proc;	
	public :
		void callCPU()
		{
			cout<<"--Choose Your CPU Type--\n";
			cout<<"(1)Intel Series, (2)Ryzen Series\n";
			cin>>ch;
			switch(ch)
			{
				case 1:
					cout<<"--Choose Your Processor--\n";
					cout<<"(1)Core2Duo, (2)Core i3, (3)Corei5, (4)Core i7\n";
					cin>>proc;
					switch(proc)
					{
						case 1:
							cout<<"Processor Chosen : Core2Duo";
							CpuName = "Core2Duo";
							MotherBoardAdded = true;
							price = 3500;
							break;
						case 2:
							cout<<"Processor Chosen : Corei3";
							CpuName = "Corei3";
							price = 16800;
							break;
						case 3:
							cout<<"Processor Chosen : Corei5";
							CpuName = "Corei5";
							price = 30500;
							break;
						case 4:
							cout<<"Processor Chosen : Corei7";
							CpuName = "Corei7";
							price = 65700;
							break;
					}
					break;
				case 2:
					cout<<"--Choose Your Processor--\n";
					cout<<"(1)Ryzen 3, (2)Ryzen 5, (3)Ryzen 7\n";
					cin>>proc;
					switch(proc)
					{
						case 1:
							cout<<"Processor Chosen : Ryzen 3";
							CpuName = "Ryzen 3";
							price = 23500;
							break;
						case 2:
							cout<<"Processor Chosen : Ryzen 5";
							CpuName = "Ryzen 5";
							price = 39500;
							break;
						case 3:
							cout<<"Processor Chosen : Ryzen 7";
							CpuName = "Ryzen 7";
							price = 63900;
							break;
					}
					break;
			}
		}
};

class PSU : public parts{
	
	public :
		void callPSU()
		{
			cout<<"-Choose Your Power Supply-\n";
			cout<<"(1)500W,(2)650W\n";
			cout<<"Enter : ";cin>>ch;
			switch(ch)
			{
				case '1':
					cout<<"500W Choosen";
					price=5500;
					CpuName = "500W";
					cout<<"\t\tPrice = "<<price;
					break;
				case '2':
					cout<<"650W Choosen";
					price=7800;
					CpuName = "650W";
					cout<<"\t\tPrice = "<<price;
					break;
			}
		}
};

class GPU : public parts{
	public:	
	void callGpu()
	{
		cout<<"-Choose Manufacturer-\n";
		cout<<"(1)Nvidia, (2)AMD";
		cout<<"Enter : ";cin>>ch;
		switch(ch)
			{
				case '1':
					cout<<"____Nvidia____\n";
					cout<<"Choose Your GPU\n";
					cout<<"1 - Nvidia GTX 750 Ti\n";//Price = 11000
					cout<<"2 - Nvidia GTX 1050 Ti\n";//Price = 26500
					cout<<"3 - Nvidia GTX 1060 Ti\n";//Price = 47850
					cout<<"4 - Nvidia GT 1030\n";//Price = 15500
					cout<<"5 - Nvidia GTX 1650 Super\n";//Price = 41500
					cin>>ch;
					switch(ch)
					{
						case '1':						
						price = 11000;
						CpuName = "Nvidia GTX 750 Ti";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
						case '2':						
						price = 26500;
						CpuName = "Nvidia GTX 1050 Ti";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
						case '3':						
						price = 47850;
						CpuName = "Nvidia GTX 1060 Ti";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
						case '4':						
						price = 15500;
						CpuName = "Nvidia GTX 1030";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
						case '5':						
						price = 41500;
						CpuName = "Nvidia GTX 1650 Super";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
					}
					break;
				case '2':
				cout<<"____AMD____\n";
					cout<<"Choose Your GPU\n";
					cout<<"1 - RX 470 \n";//Price = 18000
					cout<<"2 - RX 560\n";//Price = 24000
					cout<<"3 - RX 570\n";//Price = 30000
					cout<<"4 - RX 580\n";//Price = 33000
					cout<<"5 - RX 5500\n";//Price = 38500
					cin>>ch;
					switch(ch)
					{
						case '1':						
						price = 18000;
						CpuName = "RX 470";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
						case '2':						
						price = 24000;
						CpuName = "RX 560";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
						case '3':						
						price = 30000;
						CpuName = "RX 570";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
						case '4':						
						price = 33000;
						CpuName = "RX 580";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
						case '5':						
						price = 38500;
						CpuName = "RX 5500";
						cout<<CpuName<<" Choosen Price = "<<price<<endl;
						break;
					}
					break;
			}
		}
	};

main ()
{
	int Choice,TotalPrice;
	Desktop d;
	Memory M;
	CPU c;PSU p;GPU g;
	Ram r;
	
	while(Choice != 10)
	{
	stars(5);cout<<" PC Build Guide ";stars(5);
	cout<<"\n What Help Do You Require- \n";
	cout<<"1- PC Recommendation \n";
	cout<<"2- Making Custom PC\n";
	cout<<"10 - Quit\n";
	cin>>Choice;
	system("CLS");
	
	switch(Choice)
	{
		case 1:
			stars(5);cout<<"Weclome To Recommendation Menu";stars(5);
			cout<<"\n Budget Options -\n 1- 10,000\n 2- 15,000\n 3- 30,000\n";
			cout<<"\n Select Your Budget : ";cin>>Choice;cout<<endl;
			d.Recommend(Choice);
			break;
		case 2:
			stars(5);cout<<"Weclome To Custom Build Menu";stars(5);
			//HDD Here
			cout<<"\nWhat Disk Memory Type Do You Require?\n (1- SSD, 2-HDD)\n";cin>>Choice;cout<<endl;
			switch(Choice){
				case 1:
				 M.MemoryType("SSD");break;
				 case 2:
				 M.MemoryType("HDD");break;
			}	
			//RamHere
			cout<<"\n\n--Choose Your Ram--\n";
			r.callRam();
			//CPU Here
			cout<<"\n\n";
			c.callCPU();
			cout<<"\n\n";
			//PSU
			p.callPSU();
			cout<<"\n\n";
			//GPU
			g.callGpu();
			//Details
			system("CLS");
			cout<<"--Build Successful--\n";
			cout<<"Ram Size = "<<r.TRsize<<"GB\tPrice = "<<r.price<<endl;
			if(M.isHdd == true){cout<<"HDD = "<<M.HDsize<<"GB\tPrice = "<<r.price<<endl;}
			else{cout<<"SDD = "<<M.HDsize<<"GB\tPrice = "<<M.price<<endl;}
			cout<<"CPU = "<<c.CpuName<<"\t Price = "<<c.price<<endl;
			cout<<"PSU = "<<p.CpuName<<"\t Price = "<<p.price<<endl;
			cout<<"GPU = "<<g.CpuName<<"\t Price = "<<g.price<<endl;
			cout<<"Total Price = "<<c.price+M.price+r.price+p.price+g.price<<endl;
			system("pause");
			system("CLS");
			break;
	}
	}
	
}

void stars(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"*";
	}
}
