#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdio.h>
using namespace std;

int count = 0;

class NodeBinary{
	
	public:
		string index,name,rating,genre;
		NodeBinary *right;
		NodeBinary *left;
		
		NodeBinary()
		{
			index = '\0';
			name = '\0';
			rating = '\0';
			genre = '\0';
			left = NULL;
			right = NULL;
		}
		
		NodeBinary(string a,string b,string c,string d)
		{
			index = a;
			name = b;
			rating = c;
			genre = d;
			left = NULL;
			right = NULL;
		}
	
};

class List{
	
	public:
		
		bool checkIfUserExists(string a, string b)
		{
			fstream my_file1;
			
			string ch1,ch2;
			int flag = 0;
			
			my_file1.open("login_file.txt",ios::in);
			
			while(!my_file1.eof())
			{
				getline(my_file1,ch1);
				if(a == ch1)
				{
					getline(my_file1,ch2);
					if(b == ch2)
					{
						return true;
					}
					else
						flag = 0;
				}
				else
					flag = 0;
			}
			
			if(flag==0)
			{
				return false;
			}
			
			my_file1.close();	
		}
		
		bool Login()	
		{
			string a,b;
			system("cls");
			system("color F0");
			cout << "\n\n\t\t\t\t ***LOGIN***\n\n\n";			
			cout << "Enter Your Name : ";
			fflush(stdin);
			cin >> a;
			cout << "Enter Your Password : ";
			fflush(stdin);
			cin >> b;
			
			if(checkIfUserExists(a,b))
			{
				cout << "Login Successfull\n";
				system("pause");
				return true;
			}
			else
			{
				cout << "Login Failed \nIncorrect Username or Incorrect Password\n";
				system("pause");
				return false;
			}
		}	
		
		bool Signup()
		{
			string a,b;
			
			fstream my_file2;
			my_file2.open("login_file.txt",ios::app);
			
			system("cls");
			system("color F4");
			cout << "\n\n\t\t\t\t ***SIGNUP***\n\n\n";
			cout << "Enter Your Name : ";
			cin >> a;
			cout << "Enter Your Password : ";
			cin >> b;
			
			if(checkIfUserExists(a,b))
			{
				cout << "\nAccount Already Exists\n";
				system("pause");
				return false;
			}
			else
			{	
				cout << "SignUp successfull\n";
				
				my_file2 << a << endl;
				my_file2 << b << endl << endl;
			}
			
			my_file2.close();
			system("pause");
			return true;
		}
};

class BinaryTree{
	
	public:
		NodeBinary *root = NULL;
		
		NodeBinary *ReadData()
		{
			string index;
			string name;
			string rating;
			string genre;
			
			fstream file;
			file.open("test.csv",ios::in);
			
			while(true)
			{
				getline(file,index,',');
				getline(file,name,',');
				getline(file,rating,',');
				getline(file,genre);
				if(file.eof())
				{
					break;
				}
				root = Insert(root,index,name,rating,genre);
			}
			file.close();
			return root;
		}
		
		NodeBinary *Insert(NodeBinary *root, string n, string a, string b, string c)
		{
	    	if(root == NULL)
			{
				return new NodeBinary(n,a,b,c);
			}
			else if(root->index >= n)
			{
				root->left = Insert(root->left,n,a,b,c);
			}
			else if (root->index < n)
			{
				root->right = Insert(root->right,n,a,b,c);
			}
			return root;
		}
		
		NodeBinary *Inorder(NodeBinary *root)
		{
			if(root!=NULL)
			{
				Inorder(root->left);
				cout << root->index << "   " << root->name << "   " << root->rating << "   " << root->genre << endl;
				Inorder(root->right);
			}
			return root;
		}
		
		void Traverse(NodeBinary *root)
		{
			fstream file;
			
			if(count == 0)
			{	
				if(root!=NULL)
				{
					file.open("test.csv",ios::out);
					file << root->index << ',' << root->name << ',' << root->rating << ',' << root->genre << endl;
					file.close();		
					count++;
					Traverse(root->right);
					Traverse(root->left);
				}	
			}
			else
			{
				if(root!=NULL)
				{
					file.open("test.csv",ios::app);
					file << root->index << ',' << root->name << ',' << root->rating << ',' << root->genre << endl;
					count++;
					Traverse(root->right);
					Traverse(root->left);
				}
			}
			file.close();
		}
		
		NodeBinary *iterativeSearch3(NodeBinary *root, string key)
		{
			if(root!=NULL)
			{
				iterativeSearch3(root->left,key);
				if(root->rating == key)
				{
					cout << "\nName :  " << root->name << "\nRating : " << root->rating << "\nGenre : " << root->genre << endl;
				}
				iterativeSearch3(root->right,key);
			}
			return NULL;	
		}
		
		NodeBinary *iterativeSearch2(NodeBinary *root, string key)
		{
			if(root!=NULL)
			{
				iterativeSearch2(root->left,key);
				if(root->index == key)
				{
					cout << "\nName :  " << root->name << "\nRating : " << root->rating << "\nGenre : " << root->genre << endl;
				}
				iterativeSearch2(root->right,key);
			}
			return NULL;	
		}
		
		
		NodeBinary *iterativeSearch(NodeBinary *root, string key)
		{
			while(root != NULL)
			{
				if (key > root->index)
	            	root = root->right;
	        	else if (key < root->index)
	            	root = root->left;
	        	else
	            	return root; 
			}
    		return NULL;	
		}
		
		NodeBinary *InorderMin(NodeBinary *root)
		{
			NodeBinary *temp = root;
			while(temp!=NULL && temp->left!=NULL)
			{
				temp = temp->left;
			}
			return temp;
		}
		
		NodeBinary *Update(NodeBinary *root,string key)
		{
			int choice;
			string str,var;
			fstream file;
			file.open("test.csv",ios::in);
			
			system("color F2");	
			cout << "Enter what do u want to update : \n";
			cout << "1.Name\n";
			cout << "2.Rating\n";
			cout << "3.Genre\n";
			cin >> choice;
			
			if(choice == 1)
			{	
				cout << "Enter new name : \n";
				cin >> str;
			}
			else if(choice == 2)
			{	
				cout << "Enter new Rating : \n";
				cin >> str;
			}
			else if(choice == 3)
			{	
				cout << "Enter new genre : \n";
				cin >> str;
			}
			else
			{
				cout << "Enter valid choice : \n";
				return NULL;
			}
			
			while(!file.eof())
			{
				getline(file,var);
				root = iterativeSearch(root,key);
				
				if(root == NULL)
				{
					cout << "\nNot found\n";
					return NULL;
				}
				else if(choice == 1)
				{
					root->name = str;
				}
				else if(choice == 2)
				{
					root->rating = str;
				}
				else if(choice == 3)
				{
					root->genre = str;
				}
			}
			
			file.close();
			return root;
		}
		
		NodeBinary *Remove(NodeBinary *root,string key)
		{	
		
				if(root == NULL)
				{
					cout << "not found";
					return NULL;
				}
				else if(key < root->index)
				{
					root->left = Remove(root->left,key);
					
				}
				else if(key > root->index)
				{
					root->right = Remove(root->right,key);
				}
				else
				{
					if(root->left == NULL)
					{
						NodeBinary *temp = root->right;
						delete root;
						return temp;
					}
					else if(root->right == NULL)
					{
						NodeBinary *temp = root->left;
						delete root;
						return temp;
					}
					else
					{
						NodeBinary *temp = InorderMin(root->right);
						root->index = temp->index;
						root->right = Remove(root->right,temp->index);
					}
				}	
			
			return root;
		}
	
};

void gotoxy (int x, int y)
{
	COORD coord = { 0 ,0 };
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int mainmenu()
{
	
	system("color F5");
	char d[100] = "WELCOME TO MOVIES ";
	int i,j,k,l,m,choice;
	gotoxy(30,10);
	
//	for(j=0;j<60;j++)
//	{
//		Sleep(5);
//		printf("\xb2");
//	}
//	gotoxy(30,10);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,11);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,12);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,13);printf("\xB2");
//	gotoxy(30,14);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,15);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,16);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,17);printf("\xB2");
//	gotoxy(30,18);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,19);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,20);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,21);printf("\xB2");
//	gotoxy(30,22);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,23);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,24);printf("\xB2");
//	Sleep(20);
//	gotoxy(30,25);printf("\xB2");
//	 
//	gotoxy(90,10);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,11);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,12);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,13);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,14);printf("\xB2");
//	gotoxy(90,15);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,16);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,17);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,18);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,19);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,20);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,21);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,22);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,23);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,24);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,25);printf("\xB2");
//	Sleep(20);
//	gotoxy(90,20);printf("\xB2");
//	 
//	gotoxy(30,25);
//	for(j=0;j<60;j++)
//	{
//		Sleep(20);
//		printf("\xb2");
//	}
//	 
//	gotoxy(30,14);
//	for(j=0;j<60;j++)
//	{
//		Sleep(20);
//		printf("\xb2");
//	}
//	 
//	gotoxy(31,12);
//	printf("\t");
//	
//	for(m=0;m<30;m++)
//	{
//		Sleep(20);
//		printf("%c",d[m]);
//	}
//	 
	
	gotoxy(33,16);
	printf("\t \xdb\xdb\xdb\xb2 1. LOGIN");
	gotoxy(33,19);
	printf("\t \xdb\xdb\xdb\xb2 2. SIGNUP");
	gotoxy(33,22);
	printf("\t \xdb\xdb\xdb\xb2 3. EXIT");
	cout << "\n\n\n\n\n\t\t\t\tEnter Choice : ";
	fflush(stdin);
	cin >> choice;
	
	return choice;
}

int main()
{
	List L1;
	BinaryTree B1;

	int op;	
	int choice = 0;
	int option1 = 0;
	int option2 = 0;
	
	NodeBinary *root = NULL;
	NodeBinary *ptr = NULL;
	
	
	string index;
	string rating;
	string str;
	
	while(choice != 3)
	{
		system("cls");
		choice = mainmenu();
		
		switch(choice)
		{
			case 1:
				if(L1.Login())
				{
					while(option2 != 6)
					{
						system("cls");
						system("color F3");
						cout << "\n\nEnter Your Choice : \n\n";	
						cout << "1.Read All Data\n";
						cout << "2.Search Data\n";
						cout << "3.Update Data\n";
						cout << "4.Delete Data\n";
						cout << "5.Print Data\n";
						cout << "6.Exit\n";
						fflush(stdin);
						cin >> option2;
						
						
						if(option2 == 1)
						{
							root = B1.ReadData();
							system("pause");
						}
						else if(option2 == 2)
						{	
							system("color F4");
							cout << "Enter the option\n";
							cout << "1.Index\n2.Rating\n";
							cin >> op;
							if(op == 1)
							{
								cout << "Enter Index : \n";
								cin >> index;
								B1.iterativeSearch2(root,index);
								system("pause");
							}
							else if(op == 2)
							{
								cout << "Enter Rating : \n";
								cin >> rating;
								B1.iterativeSearch3(root,rating);
								system("pause");
							}
							else
							{
								cout << "Enter Valid Option";
								system("pause");
								break;
							}
						}
						else if(option2 == 3)
						{
							cout << "Enter the index you want to update : \n";
							cin >> index;
							B1.Update(root,index);
							B1.Traverse(root);
							system("pause");
						}
						else if(option2 == 4)
						{
							system("color FD");
							cout << "Enter the index you want to remove : \n";
							cin >> index;
							B1.Remove(root,index);
							B1.Traverse(root);
							system("pause");
						}
						else if(option2 == 5)
						{
							B1.Inorder(root);
							system("pause");
						}
						else if(option2 == 6)
						{
							break;
						}
						else
						{
							cout << "\nEnter Valid Option";
						}
					}
					break;
				}
				else
				{
					cout << "\nDo you want to Signup : \n";
					cout << "1.Yes \n";
					cout << "2.No\n";
					fflush(stdin);
					cin >> option1;
					
					if(option1 == 1)
					{
						if(L1.Signup());
					}
					else
					{
						break;
					}
				}
			case 2:
				if(!L1.Signup())
				{
					cout << "\nDo you want to login:\n";
					cout << "1.Yes\n";
					cout << "2.No\n";
					fflush(stdin);
					cin >> option1;
					
					if(L1.Login())
					{
						while(option2 != 6)
						{
							system("cls");
							system("color F3");
							cout << "Enter Your Choice : \n\n";	
							cout << "1.Read All Data\n";
							cout << "2.Search Data\n";
							cout << "3.Update Data\n";
							cout << "4.Delete Data\n";
							cout << "5.Print Data\n";
							cout << "6.Exit\n";
							fflush(stdin);
							cin >> option2;
							
							
							if(option2 == 1)
							{
								root = B1.ReadData();
								system("pause");
							}
							else if(option2 == 2)
							{
								system("color F4");
								cout << "Enter the option\n";
								cout << "1.Index\n2.Rating\n";
								cin >> op;
								if(op == 1)
								{
									cout << "Enter Index : \n";
									cin >> index;
									B1.iterativeSearch2(root,index);
									system("pause");
								}
								else if(op == 2)
								{
									cout << "Enter Rating : \n";
									cin >> rating;
									B1.iterativeSearch3(root,rating);
									system("pause");
								}
								else
								{
									cout << "Enter Valid Option";
									system("pause");
									break;
								}
							}
							else if(option2 == 3)
							{
								cout << "Enter the index you want to update : \n";
								cin >> index;
								B1.Update(root,index);
								B1.Traverse(root);
								system("pause");
							}
							else if(option2 == 4)
							{
								system("color FD");
								cout << "Enter the index you want to remove : \n";
								cin >> index;
								B1.Remove(root,index);	
								B1.Traverse(root);
								system("pause");
							}
							else if(option2 == 5)
							{
								B1.Inorder(root);
								system("pause");
							}
							else if(option2 == 6)
							{
								break;
							}
							else
							{
								cout << "\nEnter Valid Option";
							}
						}
						break;
					}
					else
					{
						break;
					}
					break;
				}
				break;
			case 3:
				exit(0);
				break;
			default:
				cout << "Enter Valid Choice : \n";
				break; 
		}	
	}
	
}
