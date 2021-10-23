 while(true)
    {
        cout<<"1-Insert\n2-Display\n3-Exit\n\nEnter your choice = ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            list.insert();
            break;
        case 2:
            list.display();
            break;
        case 3:
            exit(0);
        default:
            cout<<"Please enter a valid choice"<<endl;
        }
    }