#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>


using namespace std;
class account{
    public:
        account(){

        }
};
class Admin : public account{
    public:
        const  int max=100;
        const string txt_user = "adminUser.txt";
	    const string txt_pass = "adminPass.txt";
        void addAccountM(){
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
            cout << "successful" << endl;

        }
        void delAccountM(){
            string userM[max];
            string passM[max];
            fstream file1;
            fstream file2;
            string input;

            cout<<"Enter Username Of Account You Wish To Delete: ";
            cin>>input;
            file1.open("managerUser.txt", ios::in);
            file2.open("managerPass.txt", ios::in);
            
            char b[255];
            int i = 0;
            while (!file1.eof()){
                file2.getline(b,255);
                passM[i] = b;
                file1.getline(b,255);
                userM[i] = b;
                i++;
            }
            int k = 0; 
            bool flag = false;
            for(k = 0;k < i; k++){
                if( userM[k] == input) {
                    flag = true;
                    break;
                }
                else{
                    flag = false;
                }
            }
       
            ofstream temp1;
            ofstream temp2;
                      
            temp2.open("temp2.txt");
            temp1.open("temp1.txt");

            if (flag == true){
                cout << "successful !!!" << endl;
             
          
                for(int j = 0; j < i;j++){
                    if(j!=k) {
                        temp1 << userM[j]<<endl;
                        temp2 << passM[j]<<endl;
                    }
                    else continue;
                }
                file2.close();
                file1.close();
                temp1.close();
                temp2.close();
                remove("managerUser.txt");
                rename("temp1.txt","managerUser.txt");
                remove("managerPass.txt");
                rename("temp2.txt","managerPass.txt");
                
            }
            else{
                cout << "No found !!!!";
                file2.close();
                file1.close();
                temp1.close();
                temp2.close();
            }
           
            
            
            
        }
        void editAccountM(){
            string userM[max];
            string passM[max];
            fstream file1;
            fstream file2;
            string input;

            cout<<"Enter Username Of Account You Wish To Edit: ";
            cin>>input;
            file1.open("managerUser.txt", ios::in);
            file2.open("managerPass.txt", ios::in);
            
            char b[255];
            int i = 0;
            while (!file1.eof()){
                file2.getline(b,255);
                passM[i] = b;
                file1.getline(b,255);
                userM[i] = b;
                i++;
            }
            string newname;
            string newpass;
            cout << "New Name: ";
            cin >> newname;
            cout << "New Pass: ";
            cin >> newpass;
            int k = 0; 
            bool flag = false;
            for(k = 0;k < i; k++){
                if( userM[k] == input) {
                    flag = true;
                    break;
                }
                else{
                    flag = false;
                }
            }
            ofstream temp1;
            ofstream temp2;
                      
            temp2.open("temp2.txt");
            temp1.open("temp1.txt");
            if (flag == true){
                cout << "Successful !!!";
                userM[k] = newname;
                passM[k] = newname;
                for (int j = 0; j < i; j ++){
                    temp1 << userM[j] << endl;
                    temp2 << passM[j] << endl;
                }
                file2.close();
                file1.close();
                temp1.close();
                temp2.close();
                remove("managerUser.txt");
                rename("temp1.txt","managerUser.txt");
                remove("managerPass.txt");
                rename("temp2.txt","managerPass.txt");
            }
            else{
                cout << "not found !!!";
            }

        }
        void viewAccountM(){
            string userM[max];
            string passM[max];
            fstream file1;
            fstream file2;
            file1.open("managerUser.txt", ios::in);
            file2.open("managerPass.txt", ios::in);
            int i = 0;
            char b[255];
             while (!file1.eof()){
                file2.getline(b,255);
                passM[i] = b;
                file1.getline(b,255);
                userM[i] = b;
                i++;
             }
             
             cout << " ==> List of Manager accounts <== " << endl;
             for (int j = 0; j < i; j++){
                cout << userM[j] + "-" + passM[j] << endl; 
             }
             file1.close();
             file2.close();

        }
        void searchAccountM(){
            string userM[max];
            string passM[max];
            fstream file1;
            fstream file2;
            string input;
            cout << "Enter user You wish to find: ";
            cin >> input;
            file1.open("managerUser.txt", ios::in);
            file2.open("managerPass.txt", ios::in);
            int i = 0;
            char b[255];
             while (!file1.eof()){
                file2.getline(b,255);
                passM[i] = b;
                file1.getline(b,255);
                userM[i] = b;
                i++;
             }
             bool flag = false;
            int j = 0;
             for ( j ; j < i; j++){
                 if (userM[j] == input){

                    flag = true;
                    // cout << "has found !!" << endl;
                    // cout << "Your account: " + userM[j] + "\n" + "Your password: " + passM[j] << endl;
                    break;
            }
                 
             }
             if (flag == true){
                cout << "has found !!" << endl;
                cout << "Your account: " + userM[j] + "\n" + "Your password: " + passM[j] << endl;
             }
             else{
                 cout << "no found";
             }
          
                

            
            file1.close();
            file2.close();
        }
  //---------------------------------------------------------------------------------------------
        void addAccountC(){
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
        cout << "successful" << endl;
	}
        void delAccountC(){
            string userM[max];
            string passM[max];
            fstream file1;
            fstream file2;
            string input;

            cout<<"Enter Username Of Customer Account  You Wish To Delete: ";
            cin>>input;
            file1.open("customerUser.txt", ios::in);
            file2.open("customerPass.txt", ios::in);
            
            char b[255];
            int i = 0;
            while (!file1.eof()){
                file2.getline(b,255);
                passM[i] = b;
                file1.getline(b,255);
                userM[i] = b;
                i++;
            }
            int k = 0; 
            bool flag = false;
            for(k = 0;k < i; k++){
                if( userM[k] == input) {
                    flag = true;
                    break;
                }
                else{
                    flag = false;
                }
            }
       

            if (flag == true){
                ofstream temp1;
                ofstream temp2;
                temp1.open("temp1.txt");
                temp2.open("temp2.txt");

                for(int j = 0; j < i;j++){
                    if(j!=k) {
                        temp1 << userM[j]<<endl;
                        temp2 << passM[j]<<endl;
                    }
                    else continue;
                }
                file2.close();
                file1.close();
                temp1.close();
                temp2.close();
                remove("customerUser.txt");
                rename("temp1.txt","customerUser.txt");
                remove("customerPass.txt");
                rename("temp2.txt","customerPass.txt");
                cout << "successful !!!" << endl;
            }
            else{
                cout << "No found !!!!";
            }
        }
        void editAccountC(){}
        void viewAccountC(){
            string userM[max];
            string passM[max];
            fstream file1;
            fstream file2;
            file1.open("customerUser.txt", ios::in);
            file2.open("customerPass.txt", ios::in);
            int i = 0;
            char b[255];
             while (!file1.eof()){
                file2.getline(b,255);
                passM[i] = b;
                file1.getline(b,255);
                userM[i] = b;
                i++;
             }
             
             cout << " ==> List of Customer accounts <== " << endl;
             for (int j = 0; j < i; j++){
                cout << userM[j] + "-" + passM[j] << endl; 
             }
        }
        void searchAccountC(){
            string userM[max];
            string passM[max];
            fstream file1;
            fstream file2;
            string input;
            cout << "Enter user You wish to find: ";
            cin >> input;
            file1.open("customerUser.txt", ios::in);
            file2.open("customerPass.txt", ios::in);
            int i = 0;
            char b[255];
             while (!file1.eof()){
                file2.getline(b,255);
                passM[i] = b;
                file1.getline(b,255);
                userM[i] = b;
                i++;
             }
        
             for (int j = 0; j < i; j++){
                if (userM[j] == input){
                    cout << "has found !!" << endl;
                    cout << "Your account: " + userM[j] + "\n" + "Your password: " + passM[j] << endl;
                    break;
                
                }
                else{
                    cout << "" ;
                    break;
                }
                
             }
            file1.close();
            file2.close();
        }
};
class Manager : public account{
    public:
        const  int max=100;
        void addOrder(){
            string orderID, customerID;
            fstream File;
            File.open("managerOrders.txt", ios::app);
            cout << "Please Enter Order ID: " << endl;
            cin >> orderID;
            cout << "Please Enter Customer ID: " << endl;
            cin >> customerID;
            File << endl << orderID << "," << customerID;
            File.close();
        }
        void delOrder(){
            fstream file;
            ofstream temp;
            file.open("managerOrders.txt", ios::in);
            temp.open("temp.txt");
            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            char input;
            cout << "Enter ID Order you wish to delete: ";
            cin >> input;
            bool flag = false;
            int k = 0;
            for (k; k < i; k++){
                if (array[k][0] == input){
                    flag = true;
                    break;
                }
            }
            if (flag == true){
                cout << "sucessful !!!";
                for (int j = 0; j < i; j++){
                    if (j != k){
                        temp << array[j] << endl;
                    }   
                }
            }
            else{
                cout << ", Sorry, No found Your ID";
            }
            file.close();
            temp.close();
            remove("managerOrders.txt");
            rename("temp.txt", "managerOrders.txt");
         
           
        }
        void editOrder(){
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
        void viewOrder(){
            string user[max];
            fstream file;
            file.open("managerOrders.txt", ios::in);

            int i = 0;
            char b[255];
             while (!file.eof()){
                file.getline(b,255);
                user[i] = b;
                i++;
             }
             for (int j = 0; j < i; j++){
                 cout << user[j] << endl;
             }
             file.close();
             
        }
        void searchOrder(){
             fstream file; 
            file.open("managerOrders.txt", ios::in);
            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            char input;
            cout << "Enter Medicine ID You wish to search: ";
            cin >> input;
            bool flag = false;
            int j = 0;
            for ( j = 0; j < i; j++){
                 if (array[j][0] == input){

                    flag = true;
                    break;
                 }

             }
             if (flag == true){
                 cout << "has found !!!" << endl;
                 cout << array[j] << endl;

             }
             else {
                 cout << "No found !!!!" << endl;
             }


           file.close();
        

        }
        //---------------------------------------------------------------
        void addMedicine(){
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
            // cout << "Please Enter Order ID: " << endl;
            // cin >> ID;
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

            File << medicineID << ", " << medicineName << ", " << manuDate << ", " << expDate << " VND " << medicinePrice;
            File.close();
        }
        void delMedicine() {
            fstream file;
            ofstream temp;
            file.open("managerMedicine.txt", ios::in);
            temp.open("temp.txt");
            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            char input;
            cout << "Enter Medicine ID you wish to delete: ";
            cin >> input;
            bool flag = false;
            int k = 0;
            for (k; k < i; k++){
                if (array[k][0] == input){
                    flag = true;
                    break;
                }
            }
            if (flag == true){
                cout << "sucessful !!!";
                for (int j = 0; j < i; j++){
                    if (j != k){
                        temp << array[j] << endl;
                    }   
                }
                file.close();
                temp.close();
                remove("managerMedicine.txt");
                rename("temp.txt", "managerMedicine.txt");
            }
            else{
                cout << ", Sorry, No found Your ID" << endl;
                file.close();
                temp.close();
            }
 
   
        }
        void editMedicine(){
            fstream file;
            ofstream temp;
            file.open("managerMedicine.txt", ios::in);
            temp.open("temp.txt");
            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            char input;
            cout << "Enter Medicine ID you wish to edit: ";
            cin >> input;
            bool flag = false;
            int k = 0;
            for (k; k < i; k++){
                if (array[k][0] == input){
                    flag = true;
                    break;
                }
            }
            string ID;
            string name;
            string NSX;
            string dayout;
            string price;
            string ID_order;
            if (flag == true){
                cout << "sucessful !!!" << endl;
                cout << "Enter ID New: " << endl;
                cin >> ID;
                cout << "Enter Name_medicine new: " << endl;
                cin >> name;
                cout << "Enter Manufacture Name new: " << endl;
                cin >> NSX;
                cout << "Enter Medicine Expiry Date new: " << endl;
                cin >> dayout;
                cout << "Enter Medicine Price New: " << endl;
                cin >> price;
                // cout << "Enter Id_oder: " << endl; 
                // cin >> ID_order;

                string l = ID + ", " + name + ", " + NSX + ", " + dayout + ", "  + "VND " + price;

                array[k] = l;
                for (int j = 0; j < i; j++){
                    temp << array[j] << endl;
                }



                file.close();
                temp.close();
                remove("managerMedicine.txt");
                rename("temp.txt", "managerMedicine.txt");
            }
            else{
                cout << ", Sorry, No found Your ID" << endl;
                file.close();
                temp.close();
            }
        }
        void viewMedicine(){
            fstream file;
      
            file.open("managerMedicine.txt", ios::in);

            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            for (int j = 0; j < i; j++){
                cout << array[j] << endl;
            }
            file.close();
        }
        void searchMedicine(){
             fstream file; 
            file.open("managerMedicine.txt", ios::in);
            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            char input;
            cout << "Enter Medicine ID You wish to search: ";
            cin >> input;
            bool flag = false;
            int j = 0;
            for ( j = 0; j < i; j++){
                 if (array[j][0] == input){

                    flag = true;
                    break;
                 }

             }
             if (flag == true){
                 cout << "has found !!!" << endl;
                 cout << array[j] << endl;

             }
             else {
                 cout << "No found !!!!" << endl;
             }


           file.close();
        }
};
class Customer : public account{
    public:
        const int max = 100;
        void displayMedicine(){
            fstream file;
      
            file.open("managerMedicine.txt", ios::in);

            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            for (int j = 0; j < i; j++){
                cout << array[j] << endl;
            }
            file.close();
        };
        void searchMedicine(){
            fstream file; 
            file.open("managerMedicine.txt", ios::in);
            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            char input;
            cout << "Enter Medicine ID You wish to search: ";
            cin >> input;
            bool flag = false;
            int j = 0;
            for ( j = 0; j < i; j++){
                 if (array[j][0] == input){

                    flag = true;
                    break;
                 }

             }
             if (flag == true){
                 cout << "Informations About Your Medicine: " << endl;
                 cout << array[j] << endl;

             }
             else {
                 cout << "No found !!!!" << endl;
             }


           file.close();
        }
        void addToCart(){
            fstream file;
            file.open("managerMedicine.txt", ios::in);
            fstream temp;
            temp.open("addToCart.txt",ios::app);
            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            bool flag = false;
            char input;
            cout << "Enter Medicine ID you wish to Add : ";
            cin >> input;
            int k = 0;
            for (k; k < i; k++){
                if (array[k][0] == input){
                    flag = true;
                    break;
                }
            }
            if ( flag == false){
                cout << "Sorry, No found Your medicine ID" << endl;
                file.close();
                temp.close();
            }
            else{
                cout << "successful !!!" << endl;
                temp <<  array[k] << endl;
                file.close();
                temp.close();
            }

        }
        void displaybill(){
            fstream file;
            file.open("addToCart.txt", ios::in);
            string array[max];
            int i = 0;
            char b[255];
            while (!file.eof()){
                file.getline(b,255);
                array[i] = b;
                i++;
            }
            cout << "List of Medicine You has bill: " << endl;
            for (int j = 0; j < i; j++){
                cout << array[j] << endl;
            }
            file.close();
        }

};
bool authentication(string fileName_username, string fileName_password)
{
    int size = 0, size2 = 0;
    string username, password, user, pass, userInfo, passInfo;
    cout << "Please Enter Your Username" << endl;
	cin >> user;
	cout << "Please Enter Your Password" << endl;
	cin >> pass;

    fstream File1, File2;
	File1.open(fileName_username, ios::in);
	File2.open(fileName_password, ios::in);
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
						cout << "Truy cap thanh cong !!!" << endl;
						return true;
					}
				}
			}
		}


	}
    cout << "Truy cap bi tu choi!!!" << endl;
	File1.close();
	File2.close();
	return false;



}
int main(){
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
	
   