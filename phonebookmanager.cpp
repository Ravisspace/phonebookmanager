#include <iostream>
#include<cstring>
using namespace std;
class dnode
{
    public:
        char number[50];
        char gmail[40];
        char name[30];
        dnode *prev,*next;
        dnode(char n[],char r[],char g[])
{
               strcpy(name,n);
               strcpy(number,r);
               strcpy(gmail,g);
                next=NULL;
                prev=NULL;
}
	friend class dlist;
};
class dlist
{
    dnode *head,*temp,*ptr;

    dnode *ptr1, *ptr2, *dup;
    public:
    dnode *prevn;

    void insert();
    void sort();
    void deletecontact(char n[20]);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);

        // dnode *head,*temp,*ptr;
        // friend class apply;
        void accept();
        void display();
        void update(char ch[10]);
        dlist()
                {
                        head=NULL;
                        temp=NULL;
                        ptr=NULL;
                        ptr1=NULL;
                        ptr2=NULL;
                        dup=NULL;
                }
};
// class apply()
// {

// }
void dlist::accept()
{
        char number[50];
        char gmail[40];
        char name[30];
    char ans;
      do
        {
    cout<<"ENTER NAME :";
    cin>>name;
    // cin.getline (name,30);
    cout<<"ENTER  CONTACT NUMBER:";
    cin>>number;
    while(strlen(number)!=10)
    {
    cout<<"PLEASE ENTER VALID  NUMBER  :";
    cin>>number;
    }
    cout<<"ENTER G-MAIL    :";
    cin>>gmail;
    temp=new dnode(name,number,gmail);
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
       ptr=head;
		while(ptr->next!=NULL)
		{
ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
    }
	    cout<<" PRESS y to CONTINUE AND n TO DISCONTINUE";
    cin>>ans;
}while(ans=='y');

}
void dlist::display()
{
    ptr=head;//start the node
	while(ptr!=NULL)//traverse till last
	{
			cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t"<<ptr->number;
			cout<<"\nGMAIL::\t"<<ptr->gmail;
			ptr=ptr->next;
	}
}

    void dlist::insert()
    {
        accept();
    }
    void dlist::sort()
    {
        dnode *i,*j;
        int temp;
        char n[10];
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);
                   strcpy(i->name,j->name);
                   strcpy(j->name,n);
                }
            }
        }

    }
    void dlist::deletecontact(char s[20])
    {
        int c=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0)
            {
                c=1;
                break;
            }
            else
            {
                c=2;
            }
            ptr=ptr->next;
        }
        if(c==1 && ptr!=head && ptr->next!=NULL)
        {
            ptr->prev->next=ptr->next;
           ptr->next->prev=ptr->prev;
           delete(ptr);
           cout<<" CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr==head)
        {
            head=head->next;
            head->prev=NULL;
            delete(ptr);
           cout<<" CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr->next==NULL)
        {
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete(ptr);
           cout<<" CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(c==2)
        {
            cout<<"NO SUCH NAME IN CONTACT FOUND";
        }
    }
    void dlist::deletesamename()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->name,ptr2->next->name)==0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
            {
                ptr2 = ptr2->next;
        }
        }
        ptr1 = ptr1->next;
    }
    }
    void dlist::deletesamegmail()
    {
        ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->gmail,ptr2->next->gmail)==0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
            {
                ptr2 = ptr2->next;
        }
        }
        ptr1 = ptr1->next;
    }
    }
    void dlist::deletesamenumber()
    {
     ptr1=head;
        while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->number,ptr2->number)==0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
            {
                ptr2 = ptr2->next;
        }
        }
        ptr1 = ptr1->next;
    }
    }
    void dlist::searchbyname(char na[10])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->name)==0)
            {
                cout<<"NAME FOUND IN CONTACT LIST"<<endl;
                cout<<"CONTACT DETAILS ARE:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;

            }
            ptr=ptr->next;
        }
    }
    void dlist::searchbynumber(char num[20])
    {
     ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(num,ptr->number)==0)
            {
                cout<<"NUMBER FOUND IN CONTACT LIST\n"<<endl;
                cout<<"CONTACT DETAILS ARE:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;

            }
            ptr=ptr->next;
        }
    }
    void dlist::searchbygmail(char gm[20])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(gm,ptr->gmail)==0)
            {
                cout<<"G-MAIL FOUND IN CONTACT LIST\n"<<endl;
                cout<<"CONTACT DETAILS ARE:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;

            }
            ptr=ptr->next;
        }
    }
    void dlist::update(char n[20])
    {
        char ans;
        int c;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {

                do
                {
                    cout<<"\n PLEASE SELECT TO UPDATE ?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                    cout<<"ENTER THE NEW-NAME=";
                    cin>>ptr->name;
                    break;
                    case 2:
                    cout<<"ENTER  THE NEW PHONE NUMBER?";
                    cin>>ptr->number;
                    while(strlen(ptr->number)!=10)
    {
    cout<<" PLEASE ENTER THE  VALID NUMBER  :";
    cin>>ptr->number;
    }
                    break;
                    case 3:
                    cout<<"ENTER THE NEW G-MAIL";
                    cin>>ptr->gmail;
                    break;
                }
                cout<<"PRESS y TO CONTINUE UPDATING AND n TO STOP UPDATING?";
                cin>>ans;
                }while(ans=='y');
            }
            ptr=ptr->next;
        }
    }
int main()
{
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char gmail[20];
    dlist d1;
    // apply d;
    char ans;
    int ch,a;
    cout<<" +-+-+-+-+-+-+-+-+-+-+-+-+-+-+- PHONE BOOK  -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout<<"\n\nWHAT IS YOUR NAME?\n";
    cin.getline(name,20);
    cout<<"\n\n -----------------------------WELCOME -------------------------- "<<name<<"   ";
    cout<<"\n\n\n Let's Create The PhoneBook "<<name<<"  \n\n";
    d1.accept();
    d1.sort();
    do
    {
        cout<<"\n\ PLEASE SELECT YOUR OPERATION IN PHONEBOOK\n";
    cout<<"\n\n\n\n1)DISPLAY THE PHONEBOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN PHONEBOOK\n6) DELETE SAME NUMBERS IN PHONEBOOK\n7) SEARCH\n";
    cin>>ch;
    switch(ch)
    {
    case 2:
    d1.insert();
    d1.sort();
    break;

    case 1:
    // d1.sort();
    d1.display();
    break;
    case 3:

        cout<<"\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
        cin>>n;
    d1.update(n);
    d1.sort();
    break;
    case 4:
    cout<<"\nPLEASE ENTER THE CONTACT YOU WANT TO DELETE FROM PHONEBOOK\n";
    cin>>name;
    d1.deletecontact(name);
    break;
     case 5:
    d1.deletesamename();
    d1.display();
    break;
    case 6:
    d1.deletesamenumber();
    d1.display();
    break;
    case 7:
    do
    {
    cout<<"1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL";
    cin>>a;
    switch(a)
    {
        case 1:
        cout<<"ENTER THE NAME TO SEARCH\n";
        cin>>name;
        d1.searchbyname(name);
        break;
        case 2:
        cout<<"ENTER THE NUMBER TO SEARCH \n";
        cin>>number;
        d1.searchbynumber(number);
        break;
        case 3:
        cout<<"ENTER THE GMAIL TO SEARCH\n";
        cin>>gmail;
        d1.searchbygmail(gmail);
        break;
        default:cout<<"\nNO PROPER INPUT GIVEN.....\n";
    }
    cout<<"PRESS  y TO CONTINUE SEARCH AND n TO STOP SEARCH OPERATION";
    cin>>ans;
}while(ans=='y');

    break;
    case 8:d1.deletesamegmail();
    d1.display();
    break;
    default:cout<<"\n NO INPUT FOUND\n";
    }
    cout<<"\n\n PRESS y TO CONTINUE MORE OPERATIONS AND n TO  STOP FURTHER OPERATIONS";
    cin>>ans;
}while(ans=='y');
}