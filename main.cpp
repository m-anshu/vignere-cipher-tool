#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<algorithm>
using namespace std;
class Coder
{
	string k;// stores the key
	string d;// stores all alphabets 
	int l; //stores the length of key
	ofstream f1; //output stream object
	ifstream f2; //input stream object
	bool correct(string x)
	{
		for(char c:x) //checks if the entered key consists of only alphabets
		{
			if(isalpha(c))
				continue;
			else
				return false;
		}
		return true;
	}
	void entfile() // function to enter filenames
	{
		string file;
		cout<<"Enter the file to read from"<<endl;
		cin>>file;
		f2.open(file);
		while(!f2)
		{
			cout<<"enter a valid file name"<<endl;
			cin>>file;
			f2.open(file);
		}
		cout<<"Enter the file to write to"<<endl;
		cin>>file;
		f1.open(file);
		while(!f1)
		{
			cout<<"enter a valid file name"<<endl;
			cin>>file;
			f1.open(file);
		}
	}
	public:
	Coder() // constructor
	{
		entfile();
		cout<<"Enter the Key"<<endl;
		cin>>k;
		//getline(cin,k);
		int x=0;
		while(!(correct(k)))
		{
			cout<<"Please neter a valid key"<<endl;
			cin>>k;
			//getline(cin,k);
		}
		l=k.length();
	}
	void display() // display function mainly for testing
	{
		cout<<k<<endl;
		cout<<l<<endl;
	}
	void encode() //function to encode the message
	{
		int n=0;
		int a;
		int b;
		char chx;
		char chy;
		char chf;
		while(f2.get(chx))
		{
			//cout<<chx;
			if(!isalpha(chx))
			{
				f1.put(chx);
				continue;
			}
			chy=k[n];
			chx=tolower(chx);
			chy=tolower(chy);
			a=chx-97;
			b=chy-97;
			a=(a+b)%26;
			chf=a+97;
			f1.put(chf);
			n++;
			n=n%l;
		}
		f1.close();
		f2.close();
	}
	void decrypt()
    {
		int n=0;
		int a=0;
		int b=0;
		char chx;
		char chy;
		char chf;
		while(f2.get(chx))
		{
			if(!isalpha(chx))
			{
				f1.put(chx);
				continue;
			}
			chy=k[n];
			chx=tolower(chx);
			chy=tolower(chy);
			a=chx-97;
			b=chy-97;
			a=a-b;
			if(a<0)
				a+=26;
			chf=a+97;
			f1.put(chf);
			n++;
			n=n%l;
		}
		f1.close();
		f2.close();
		return;
    }
	void doublee()
	{
		cout<<"Double Encryption"<<endl;
		int n=0;
		int a;
		int b;
		char chx;
		char chy;
		char chf;
		string t="";
		while(f2.get(chx))
		{
			//cout<<chx;
			if(!isalpha(chx))
			{
				cout<<chx<<" "<<chx<<endl;
				t+=chx;
				continue;
			}
			chy=k[n];
			chx=tolower(chx);
			chy=tolower(chy);
			a=chx-97;
			b=chy-97;
			a=(a+b)%26;
			chf=a+97;
			t+=chf;
			n++;
			n=n%l;
		}
		a=0;
		n=0;
		b=0;
		int ll=t.length();
		reverse(k.begin(),k.end());
		int xx=0;
		while(xx<ll)
		{
			chx=t[xx];
			xx++;
			if(!isalpha(chx))
			{
				f1.put(chx);
				continue;
			}
			chy=k[n];
			chx=tolower(chx);
			chy=tolower(chy);
			a=chx-97;
			b=chy-97;
			a=(a+b)%26;
			chf=a+97;
			f1.put(chf);
			n++;
			n=n%l;
		}
		f1.close();
		f2.close();
		return;
	}
	void doubled()
	{
		int n=0;
		int a=0;
		int b=0;
		char chx;
		char chy;
		char chf;
		reverse(k.begin(),k.end());
		string t="";
		while(f2.get(chx))
		{
			if(!isalpha(chx))
			{
				t+=chx;
				continue;
			}
			chy=k[n];
			chx=tolower(chx);
			chy=tolower(chy);
			a=chx-97;
			b=chy-97;
			a=a-b;
			if(a<0)
				a+=26;
			chf=a+97;
			t+=chf;
			n++;
			n=n%l;
		}
		n=0;
		a=0;
		b=0;
		reverse(k.begin(),k.end());
		int xx=0;
		int ll=t.length();
		while(xx<ll)
		{
			chx=t[xx];
			xx++;
			if(!isalpha(chx))
			{
				f1.put(chx);
				continue;
			}
			chy=k[n];
			chx=tolower(chx);
			chy=tolower(chy);
			a=chx-97;
			b=chy-97;
			a=a-b;
			if(a<0)
				a+=26;
			chf=a+97;
			f1.put(chf);
			n++;
			n=n%l;
		}
		f1.close();
		f2.close();
		return;
	}
};

int main()
{
    int e=0;
    while(1){
    system("cls");
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"                VIGNERE CIPHER TOOL"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"                         MENU"<<endl;
    cout<<""<<endl;
    cout<<"1 -> Single Layer Encryption"<<endl;
    cout<<""<<endl;
    cout<<"2 -> Single Layer Decryption"<<endl;
    cout<<""<<endl;
    cout<<"3 -> Double Layer Encryption"<<endl;
    cout<<""<<endl;
    cout<<"4 -> Double Layer Decryption"<<endl;
    if(e)
	{
        cout<<"Invalid input. Please Try Again."<<endl;
    }
	int m=0;
	cin>>m;
	if(m!=1 && m!=2 &&m!=3 &&m!=4)
	{
        e=1;
        continue;
	}
	Coder obj;
	if(m==1)
		obj.encode();
	else if(m==2)
		obj.decrypt();
	else if(m==3)
		obj.doublee();
	else
		obj.doubled();
	return 0;
    }
}