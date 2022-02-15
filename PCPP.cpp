#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>

using namespace std;

class accounts
{
public:
	accounts()
	{

	}
};

class Admin : public accounts
{
public:
	const string txt_user = "adminUser.txt";
	const string txt_pass = "adminPass.txt";

	void addAccountM()
	{
		string username, password;
		fstream File1, File2;
		File1.open("managerUser.txt", ios::app);
		File2.open("managerPass.txt", ios::app);
		cout << "Please Enter Username: " << endl;
		cin >> username;
		cout << "Please Enter Password: " << endl;
		cin >> password;
		File1 << endl << username;
		File2 << endl << password;
	}
	void delAccountM()
	{
		// deleting username

		string username, user;
		cout << "Enter Username Of Account You Wish To Delete: ";
		cin >> user;
		
		// ufile for usernames file

		ifstream ufile;	
		ufile.open("managerUser.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(ufile, username))
		{
			if (username != user)
			{
				temp << username << endl;
			}
		}
		ufile.close();
		temp.close();
		remove("managerUser.txt");
		rename("temp.txt", "managerUser.txt");

		// deleting password

		string password, pass;
		cout << "Enter Username Of Account You Wish To Delete: ";
		cin >> pass;

		// pfile for password file

		ifstream pfile;
		pfile.open("managerPass.txt");
		ofstream temp2;
		temp2.open("temp2.txt");
		while (getline(pfile, password))
		{
			if (password != pass)
			{
				temp2 << password << endl;
			}
		}
		pfile.close();
		temp2.close();
		remove("managerPass.txt");
		rename("temp2.txt", "managerPass.txt");
		cout << "Deleted!" << endl;

	}
	void editAccountM()
	{
		// deleting username
		// uinput is the username input

		string username, user, uinput;
		cout << "Enter Username Of Account You Wish To Edit: ";
		cin >> user;

		// ufile for usernames file

		ifstream ufile;
		ufile.open("managerUser.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(ufile, username))
		{
			if (username != user)
			{
				temp << username << endl;
			}
			else
			{
				cout << "Enter New Username: ";
				cin >> uinput;
				temp << uinput << endl;
			}
		}
		ufile.close();
		temp.close();
		remove("managerUser.txt");
		rename("temp.txt", "managerUser.txt");

		//deleting password
		//pinput is password input

		string password, pass, pinput;
		cout << "Enter Username Of Account You Wish To Edit: ";
		cin >> pass;

		//pfile for password file

		ifstream pfile;
		pfile.open("managerPass.txt");
		ofstream temp2;
		temp2.open("temp2.txt");
		while (getline(pfile, password))
		{
			if (password != pass)
			{
				temp2 << password << endl;
			}
			else
			{
				cout << "Enter New Username: ";
				cin >> pinput;
				temp2 << pinput << endl;
			}
		}
		pfile.close();
		temp2.close();
		remove("managerPass.txt");
		rename("temp2.txt", "managerPass.txt");
		cout << "Edited!" << endl;

	}
	void viewAccountM()
	{
		//uinput is the username input

		string username, uinput;

		//ufile for usernames file

		ifstream ufile;
		ufile.open("managerUser.txt");
		ofstream temp;
		temp.open("temp.txt");
		cout << "All Usernames:" << endl;
		while (getline(ufile, username))
		{
			cout << username << endl;
		}
		cout << endl;//password
		string password, pinput;//pinput is password input
		ifstream pfile;//pfile for password file
		pfile.open("managerPass.txt");
		ofstream temp2;
		temp2.open("temp2.txt");
		cout << "All Passwords:" << endl;
		while (getline(pfile, password))
		{
			cout << password << endl;
		}

	}
	void searchAccountM()
	{
		//deleting username

		string username, user, uinput;//uinput is the username input
		cout << "Enter Username Of Account You Wish To Search: ";
		cin >> user;
		ifstream ufile;//ufile for usernames file
		ufile.open("managerUser.txt");
		while (getline(ufile, username))
		{
			if (username == user)
			{
				cout << "User: " << username << " Found." << endl;
			}
		}
		ufile.close();

		//deleting password

		string password, pass, pinput;//pinput is password input
		cout << "Enter Password Of Account You Wish To Search: ";
		cin >> pass;
		ifstream pfile;//pfile for password file
		pfile.open("managerPass.txt");
		while (getline(pfile, password))
		{
			if (password == pass)
			{
				cout << "Password: " << password << " Found." << endl;
			}
		}
		pfile.close();
		cout << "Search Complete" << endl;
	}

	void addAccountC()
	{
		string username, password;
		fstream File1, File2;
		File1.open("customerUser.txt", ios::app);
		File2.open("customerPass.txt", ios::app);
		cout << "Please Enter Username: " << endl;
		cin >> username;
		cout << "Please Enter Password: " << endl;
		cin >> password;
		File1 << endl << username;
		File2 << endl << password;
	}
	void delAccountC()
	{
		//deleting username

		string username, user;
		cout << "Enter Username Of Account You Wish To Delete: ";
		cin >> user;
		ifstream ufile;//ufile for usernames file
					   //ufile.open("adminUser.txt");
		ufile.open("customerUser.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(ufile, username))
		{
			if (username != user)
			{
				temp << username << endl;
			}
		}
		ufile.close();
		temp.close();
		remove("customeUser.txt");
		rename("temp.txt", "customerUser.txt");

		//deleting password

		string password, pass;
		cout << "Enter Username Of Account You Wish To Delete: ";
		cin >> pass;
		ifstream pfile;//pfile for password file
		pfile.open("customerPass.txt");
		ofstream temp2;
		temp2.open("temp2.txt");
		while (getline(pfile, password))
		{
			if (password != pass)
			{
				temp2 << password << endl;
			}
		}
		pfile.close();
		temp2.close();
		remove("customerPass.txt");
		rename("temp2.txt", "customerPass.txt");
		cout << "Deleted!" << endl;

	}
	void editAccountC()
	{
		//deleting username
		string username, user, uinput;//uinput is the username input
		cout << "Enter Username Of Account You Wish To Edit: ";
		cin >> user;
		ifstream ufile;//ufile for usernames file
		ufile.open("customerUser.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(ufile, username))
		{
			if (username != user)
			{
				temp << username << endl;
			}
			else
			{
				cout << "Enter New Username: ";
				cin >> uinput;
				temp << uinput << endl;
			}
		}
		ufile.close();
		temp.close();
		remove("customerUser.txt");
		rename("temp.txt", "customerUser.txt");

		//deleting password

		string password, pass, pinput;//pinput is password input
		cout << "Enter Username Of Account You Wish To Edit: ";
		cin >> pass;
		ifstream pfile;//pfile for password file
		pfile.open("customerPass.txt");
		ofstream temp2;
		temp2.open("temp2.txt");
		while (getline(pfile, password))
		{
			if (password != pass)
			{
				temp2 << password << endl;
			}
			else
			{
				cout << "Enter New Username: ";
				cin >> pinput;
				temp2 << pinput << endl;
			}
		}
		pfile.close();
		temp2.close();
		remove("customerPass.txt");
		rename("temp2.txt", "customerPass.txt");
		cout << "Edited!" << endl;

	}
	void viewAccountC()
	{
		string username, uinput;//uinput is the username input

		ifstream ufile;//ufile for usernames file
		ufile.open("customerUser.txt");
		ofstream temp;
		temp.open("temp.txt");
		cout << "All Usernames: " << endl;
		while (getline(ufile, username))
		{
			cout << username << endl;
		}
		cout << endl;//password
		string password, pinput;//pinput is password input
		ifstream pfile;//pfile for password file
		pfile.open("customerPass.txt");
		ofstream temp2;
		temp2.open("temp2.txt");
		cout << "All Passwords: " << endl;
		while (getline(pfile, password))
		{
			cout << password << endl;
		}

	}
	void searchAccountC()
	{
		//deleting username
		string username, user, uinput;//uinput is the username input
		cout << "Enter Username Of Account You Wish To Search: ";
		cin >> user;
		ifstream ufile;//ufile for usernames file
		ufile.open("customerUser.txt");
		while (getline(ufile, username))
		{
			if (username == user)
			{
				cout << "User: " << username << " Found." << endl;
			}
		}
		ufile.close();

		//deleting password

		string password, pass, pinput;//pinput is password input
		cout << "Enter Password Of Account You Wish To Search: ";
		cin >> pass;
		ifstream pfile;//pfile for password file
		pfile.open("customerPass.txt");
		while (getline(pfile, password))
		{
			if (password == pass)
			{
				cout << "Password: " << password << " Found." << endl;
			}
		}
		pfile.close();
		cout << "Search Complete" << endl;
	}

};

class Manager : public accounts
{
public:
	void addOrder()
	{
		string orderID, customerID;
		fstream File;
		File.open("managerOrders.txt", ios::app);
		cout << "Please Enter Order ID: " << endl;
		cin >> orderID;
		cout << "Please Enter Customer ID: " << endl;
		cin >> customerID;
		File << endl << orderID << "," << customerID;

	}
	void addMedicine()
	{
		string medicineID, medicineName, medicinePrice, manuDate, expDate;
		fstream File;
		cout << "Please Enter Medicine ID: " << endl;
		cin >> medicineID;
		cout << "Please Enter Medicine Name: " << endl;
		cin >> medicineName;
		cout << "Please Enter Medicine Manufacture Date: " << endl;
		cin >> manuDate;
		cout << "Please Enter Medicne Expiry Date: " << endl;
		cin >> expDate;
		cout << "Please Enter Medicine Price: " << endl;
		cin >> medicinePrice;
		File.open("managerMedicine.txt", ios::app);
		string orderID, ID;
		cout << "Please Enter Order ID: ";
		cin >> ID;
		ifstream file;//ufile for usernames file
		file.open("managerMedicine.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, orderID))
		{
			if (orderID == ID)
			{
				cout << "Medicine Exists." << endl;
				return;
			}
		}
		file.close();
		temp.close();
		remove("managerMedicine.txt");
		rename("temp.txt", "managerMedicine.txt");

		File << endl << medicineID << ", " << medicineName << ", " << manuDate << ", " << expDate << ", RM " << medicinePrice;
		File.close();
	}
	void delOrder()
	{
		//deleting username
		int p = 0;
		string orderID, ID;
		cout << "Please Enter Order ID: ";
		cin >> ID;
		ifstream file;//ufile for usernames file
		file.open("managerOrders.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, orderID))
		{
			p = orderID.find_first_of(",");
			if (ID != orderID.substr(0, p))
			{
				temp << orderID << endl;
			}
		}
		file.close();
		temp.close();
		remove("managerOrders.txt");
		rename("temp.txt", "managerOrders.txt");
	}
	void delMedicine()
	{
		//deleting username
		int p;
		string medicineID, ID;
		cout << "Please Enter Medicine ID: ";
		cin >> ID;
		ifstream file;//ufile for usernames file
		file.open("managerMedicine.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, medicineID))
		{
			p = ID.find_first_of(",");
			if (ID != medicineID.substr(0, p))
			{
				temp << medicineID << endl;
			}
		}
		file.close();
		temp.close();
		remove("managerMedicine.txt");
		rename("temp.txt", "managerMedicine.txt");
	}
	void editOrder()
	{
		//deleting username
		int p;
		string orderID, ID, input, customerID;//uinput is the username input
		cout << "Please Enter Order ID ";
		cin >> ID;
		ifstream file;//ufile for usernames file
		file.open("managerOrders.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, orderID))
		{
			p = orderID.find_first_of(",");
			if (ID != orderID.substr(0, p))
			{
				temp << orderID << endl;
			}
			else
			{
				cout << "Please Enter Order ID: " << endl;
				cin >> orderID;
				cout << "Please enter Customer ID: " << endl;
				cin >> customerID;
				temp << orderID << "," << customerID << endl;
			}
		}
		file.close();
		temp.close();
		remove("managerOrders.txt");
		rename("temp.txt", "managerOrders.txt");
	}
	void editMedicine()
	{
		//deleting username
		int p;
		string ID, medicineID, medicineName, manuDate, expDate, medicinePrice;//uinput is the username input
		cout << "Please Enter Order ID ";
		cin >> ID;
		ifstream file;//ufile for usernames file
		file.open("managerMedicine.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, medicineID))
		{
			p = medicineID.find_first_of(",");
			if (ID != medicineID.substr(0, p))
			{
				temp << medicineID << endl;
			}
			else
			{
				cout << "Please Enter Medicine ID: " << endl;
				cin >> medicineID;
				cout << "Please Enter Medicine Name: " << endl;
				cin >> medicineName;
				cout << "Please Enter Medicine Manufacture Date: " << endl;
				cin >> manuDate;
				cout << "Please Enter Medicne Expiry Date: " << endl;
				cin >> expDate;
				cout << "Please Enter Medicine Price: " << endl;
				cin >> medicinePrice;
				temp << medicineID << ", " << medicineName << ", " << manuDate << ", " << expDate << ", RM " << medicinePrice << endl;
			}
		}
		file.close();
		temp.close();
		remove("managerMedicine.txt");
		rename("temp.txt", "managerMedicine.txt");
	}
	void viewOrder()
	{
		string orderID;//uinput is the username input
		ifstream file;//ufile for usernames file
		file.open("managerOrders.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, orderID))
		{
			cout << orderID << endl;
		}
	}
	void viewMedicine()
	{
		string medicineID;//uinput is the username input
		ifstream file;//ufile for usernames file
		file.open("managerMedicine.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, medicineID))
		{
			cout << medicineID << endl;
		}
	}
	void searchOrder()
	{
		//deleting username
		string orderID, ID;//uinput is the username input
		int p;
		cout << "Please Enter Order ID ";
		cin >> ID;
		ifstream file;//ufile for usernames file
		file.open("managerOrders.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, orderID))
		{
			p = orderID.find_first_of(",");
			if (ID == orderID.substr(0, p))
			{
				cout << orderID << endl;
			}
		}
		file.close();
		temp.close();
		remove("managerOrders.txt");
		rename("temp.txt", "managerOrders.txt");
	}
	void searchMedicine()
	{
		string medicineID, ID;//uinput is the username input
		int p;
		cout << "Please Enter Medicine ID ";
		cin >> ID;
		ifstream file;//ufile for usernames file
		file.open("managerMedicine.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, medicineID))
		{
			p = medicineID.find_first_of(",");
			if (ID == medicineID.substr(0, p))
			{
				cout << medicineID << endl;
			}
		}
		file.close();
		temp.close();
		remove("managerMedicine.txt");
		rename("temp.txt", "managerMedicine.txt");
	}

};

class Customer : public accounts
{
public:
	void displayMedicine()
	{
		string medicineID;//uinput is the username input
		ifstream file;//ufile for usernames file
		file.open("managerMedicine.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, medicineID))
		{
			cout << medicineID << endl;
		}
	}
	void searchMedicine()
	{
		string medicineID, ID;//uinput is the username input
		int p;
		cout << "Please Enter Medicine ID ";
		cin >> ID;
		ifstream file;//ufile for usernames file
		file.open("managerMedicine.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, medicineID))
		{
			p = medicineID.find_first_of(",");
			if (ID == medicineID.substr(0, p))
			{
				cout << medicineID << endl;
			}
		}
		file.close();
		temp.close();
		remove("managerMedicine.txt");
		rename("temp.txt", "managerMedicine.txt");
	}
	void addToCart()
	{
		string medicineID, ID, Price, temp;
		int p = 0;//This is to find the price of the product
		fstream File, File2;
		cout << "Please Enter Medicine ID: " << endl;
		cin >> medicineID;
		File.open("managerMedicine.txt");
		File2.open("customerCart.txt", ios::app);
		while (getline(File, ID))
		{
			p = ID.find_first_of(",");
			if (medicineID == ID.substr(0, p))
			{
				temp = ID.substr(ID.find(".") + 1, ID.length());
				File2 << temp << endl;
			}


		}
		File.close();
	}
	void displaybill()
	{
		string medicinePrice;//uinput is the username input
		int price = 0, sum = 0;
		ifstream file;//ufile for usernames file
		file.open("customerCart.txt");
		ofstream temp;
		temp.open("temp.txt");
		while (getline(file, medicinePrice))
		{
			stringstream convert(medicinePrice);
			convert >> price;
			sum = price + sum;
		}
		cout << "Your Total Is: RM " << sum << endl;
	}
};

bool authentication(string fileName_username, string fileName_password)
{

	int size = 0, size2 = 0;

	string username, password, user, pass, userInfo, passInfo;//username and password will store the data from the file. user and pass will store username and password from the user.userInfo and passInfo is to take the information from the file.
	cout << "Please Enter Your Username" << endl;
	cin >> user;
	cout << "Please Enter Your Password" << endl;
	cin >> pass;
	fstream File1, File2;
	File1.open(fileName_username, ios::in);
	File2.open(fileName_password, ios::in);
	//File >> info;
	while (getline(File1, userInfo))
	{
		size = size + 1;
		if (user == userInfo)
		{
			while (getline(File2, passInfo))
			{
				size2 = size2 + 1;
				if (pass == passInfo)
				{
					if (size == size2)
					{
						cout << "Access Granted" << endl;
						return true;
					}
				}
			}
		}


	}
	cout << "Access Denied" << endl;
	return false;
	File1.close();
	File2.close();

}
int main()
{
	int option = 0;
	bool flag = true;
	bool flag2 = true;
	while (flag == true)
	{
		//Loop starts here
		cout << "************PHARMACY MANAGEMENT SYSTEM************" << endl;
		cout << "Please Enter Your Account Type. \n1.ADMIN\n2.MANAGER\n3.CUSTOMER\n4.EXIT\n";
		cin >> option;
		switch (option)
		{
		case 1:
			if (authentication("adminUser.txt", "adminPass.txt") == true)
			{
				cout << "Please Enter Your Option:\n1.MANAGER\n2.CUSTOMER\n";
				cin >> option;
				Admin a;
				switch (option)
				{
				case 1:
					cout << "Please Enter Your Option:\n1.ADD\n2.DELETE\n3.EDIT\n4.VIEW\n5.SEARCH\n6.CANCEL\n";
					cin >> option;
					switch (option)
					{
					case 1:
						a.addAccountM();
						break;
					case 2:
						a.delAccountM();
						break;
					case 3:
						a.editAccountM();
						break;
					case 4:
						a.viewAccountM();
						break;
					case 5:
						a.searchAccountM();
						break;
					case 6:
						break;
					default:
						cout << "Please Choose An Option Between 1 and 6.";
						break;
					}
					break;
				case 2:
					cout << "Please Enter Your Option:\n1.ADD\n2.DELETE\n3.EDIT\n4.VIEW\n5.SEARCH\n6.CANCEL\n";
					cin >> option;
					switch (option)
					{
					case 1:
						a.addAccountC();
						break;
					case 2:
						a.delAccountC();
						break;
					case 3:
						a.editAccountC();
						break;
					case 4:
						a.viewAccountC();
						break;
					case 5:
						a.searchAccountC();
						break;
					case 6:
						break;
					default:
						cout << "Please Choose An Option Between 1 and 6.";
						break;
					}
					break;
				default:
					cout << "Please Choose An Option Between 1 and 6.";
					break;
				}
			}
			break;
		case 2:
			if (authentication("managerUser.txt", "managerPass.txt") == true)
			{
				Manager m;
				cout << "Please Enter Your Option:\n1.ORDERS\n2.MEDICINE\n";
				cin >> option;
				if (option == 1)
				{
					cout << "Please Enter Your Option:\n1.ADD\n2.DELETE\n3.EDIT\n4.VIEW\n5.SEARCH\n6.CANCEL\n";
					cin >> option;
					switch (option)
					{
					case 1:
						m.addOrder();
						break;
					case 2:
						m.delOrder();
						break;
					case 3:
						m.editOrder();
						break;
					case 4:
						m.viewOrder();
						break;
					case 5:
						m.searchOrder();
						break;
					case 6:
						break;
					default:
						cout << "Please Choose An Option Between 1 and 6.";
						break;
					}
				}
				else if (option == 2)
				{
					cout << "Please Enter Your Option:\n1.ADD\n2.DELETE\n3.EDIT\n4.VIEW\n5.SEARCH\n6.CANCEL\n";
					cin >> option;
					switch (option)
					{
					case 1:
						m.addMedicine();
						break;
					case 2:
						m.delMedicine();
						break;
					case 3:
						m.editMedicine();
						break;
					case 4:
						m.viewMedicine();
						break;
					case 5:
						m.searchMedicine();
						break;
					case 6:
						break;
					default:
						cout << "Please Choose An Option Between 1 and 6.";
						break;
					}
				}
				else
				{
					cout << "Please Choose An Option Between 1 and 2.";
				}

			}
			break;
		case 3:
			if (authentication("customerUser.txt", "customerPass.txt") == true)
			{
				cout << "Please Enter Your Option:\n1.DISPLAY MEDICINE\n2.SEARCH\n3.ADD TO CART\n4.DISPLAY BILL\n5.EXIT\n";
				cin >> option;
				Customer c;
				switch (option)
				{

				case 1:
					c.displayMedicine();
					break;
				case 2:
					c.searchMedicine();
					break;
				case 3:
					c.addToCart();
					break;
				case 4:
					c.displaybill();
					break;
				case 5:
					cout << "Please Choose An Option Between 1 and 5.";
					break;
				default:
					break;
				}
			}
			break;
		case 4:
			flag = false;
			break;
		default:
			cout << "Please Choose An Option Between 1 and 4.";
			break;
		}
	}
	return 0;
}