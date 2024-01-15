#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>

using namespace std;

class Product 
{
    public:
    string name;
    int price;
    int quantity;

};

class Cart 
{
    public:
    string cname;
    int cprice;
    int cquantity;

    Cart():cquantity(0){};
};

void read_products(string filename, vector<Product>& products) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "Failed to open file" << endl;
    return;
  }

  string line;
  while (getline(file, line)) 
  {
    Product product;
    istringstream iss(line);
    //used to parse the information from the line of text into individual values.
    string name, price, quantity;

    if (getline(iss, name, ' ') && getline(iss, price, ' ') && getline(iss, quantity)) {
      product.name = name;
      product.price = stod(price);
      product.quantity = stoi(quantity);

      products.push_back(product);
    } else {
      cout << "Invalid line format: " << line << endl;
    }
  }

  file.close();
}

void write_products(const string& filename, const vector<Product>& products) 
{
  ofstream file(filename);
  if (!file.is_open()) {
    throw runtime_error("Failed to open file");
  }

  for (Product product : products) 
  {
    file << product.name << " " << product.price << " " << product.quantity << endl;
  }

  file.close();
}

int checkproduct(string prod, vector<Product>& products)
{
    for (Product product : products) 
    {
        if (product.name==prod)
        {
            return 1;
        }
    }
    return 0;
}

void checkout(vector<Cart>& cart) 
{
    cout<<"......................................................"<<endl;
    cout<<"In your cart:"<<endl;
    cout << "Product   Price   Quantity"<<endl;
    int total=0;
    for (Cart item : cart) 
    {
        total=total+(item.cprice)*(item.cquantity);
        cout << item.cname << "      " << item.cprice << "      " << item.cquantity << endl;
    }
    cout << "\nYour total is: "<<total<<endl;
    cout<< "\nthank you for shopping with us!"<<endl;
    cout<<"......................................................"<<endl;

}

void seller(vector<Product>& products) {
    int option;
    while (true) {
        cout << "\n1. Add Product to store\n";
        cout << "2. Display products\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
            cout << "\nEnter product name: ";
            string name;
            cin >> name;
            int find=0;
            
            for (Product& product : products) 
            {
                if (product.name==name)
                {
                    find=1;
                    cout << "Enter Quantity: ";
                    int quantity;
                    cin >> quantity;
                    product.quantity=product.quantity+quantity;
                    cout << "\nStock added successfully.\n";
                }
                else
                {
                    // find=0;
                }
            }
            if(!find)
            {
                // cout << "\nNo item as such."<<endl;
                cout << "Enter Quantity: ";
                int quantity;
                cin >> quantity;
                cout << "Enter Price: ";
                int price;
                cin >> price;
                Product P;
                P.name=name;
                P.price=price;
                P.quantity=quantity;

                products.push_back(P);
                cout << "\nNew Item added successfully.\n";
            }
            // cout << "Stock added successfully.\n";
        } 
        else if (option == 2) 
        {
            cout<<"......................................................"<<endl;
            cout<<"\n"<<endl;
            cout << "Product   Price   Quantity"<<endl;
            for (Product product : products) 
            {
                cout << product.name << "      " << product.price << "      " << product.quantity << endl;
            }
            cout<<"\n"<<endl;
            cout<<"......................................................"<<endl;
        } 
        else if (option == 3) 
        {
            write_products("products.txt",products);
            break;
        } 
        else 
        {
            cout << "\nInvalid option. Please try again.\n";
        }
    }
}

void buyer(vector<Product> &products, vector<Cart> &cart)
{
    int option;
    while (true)
    {
        cout << "\n1. Display available products\n";
        cout << "2. Add product to cart\n";
        cout << "3. Display cart items\n" ;
        cout << "4. Delete product from cart\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: " << endl;
        cin >> option;

        if (option == 1)
        {
            cout << "......................................................" << endl;
            cout << "\n"
                 << endl;
            cout << "Product   Price   Quantity" << endl;
            for (Product product : products)
            {
                cout << product.name << "      " << product.price << "      " << product.quantity << endl;
            }
            cout << "\n"
                 << endl;
            cout << "......................................................" << endl;
        }
        else if (option == 2)
        {
            string prod_name;
            cout << "Enter product name to add to cart: ";
            cin >> prod_name;
            int find = 0;
            for (Product &product : products)
            {
                if (product.name == prod_name)
                {
                    find = 1;
                    cout << "Enter quantity: ";
                    int q;
                    cin >> q;
                    Cart c;
                    if (product.quantity < q || q < 0)
                    {
                        cout << "\nOnly " << product.quantity << " pieces available" << endl;
                        cout << "0 items were added" << endl;
                    }
                    else
                    {
                        // cout<<"a-okay"<<endl;
                        c.cname = product.name;
                        c.cprice = product.price;
                        c.cquantity = q;
                        product.quantity = product.quantity - q;
                        cart.push_back(c);

                        cout << "\nItem added" << endl;
                    }
                }
                else
                {
                    // find=0;
                }
            }
            if (!find)
            {
                cout << "\nItem not available" << endl;
            }
        }
        else if (option == 3)
        {
            cout << "......................................................" << endl;
            cout << "\n"
                 << endl;
            cout << "In your cart:" << endl;
            cout << "Product   Price   Quantity" << endl;
            for (Cart item : cart)
            {
                cout << item.cname << "      " << item.cprice << "      " << item.cquantity << endl;
            }
            cout << "\n"
                 << endl;
            cout << "......................................................" << endl;
        }
        else if (option == 4)
        {
            string prod_name;
            cout << "Enter product name to delete from cart: ";
            cin >> prod_name;
    
            int find = 0, qty=0, removed = 0;
            // vector<int>::iterator it ;
            auto it = cart.begin();

            for (Cart &item : cart)
            {
                if (item.cname == prod_name)
                {
                    find = 1;
                    cout << "(-1)Delete All of item or (Enter quantity no.)Delete Qty: ";
                    cin >> qty;
                    // cout << qty << endl;

                    if (qty == -1 || qty == item.cquantity)
                    {
                        removed = 1;
                        qty = item.cquantity;
                        cart.erase(it);
                    
                    }
                    else if ( qty < item.cquantity)
                    {
                        removed = 1;
                        item.cquantity -= qty;
                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                    }
                }

                it++;
            }

            if (find == 0)
            {
                cout << "Product not in cart" << endl;
            }
            if (removed)
            {
                for (Product &prod : products)
                {
                    if (prod.name == prod_name)
                    {
                        prod.quantity += qty;
                    }
                }
            }
        }
        
        else if (option == 5)
        {
            checkout(cart);
            write_products("products.txt", products);
            break;
        }
        else
        {
            cout << "\nInvalid option. Please try again.\n";
        }
    }
}


int main() {
    int user;
    cout << "Welcome To Clothing Store!\n";
    cout << "Enter 1(Seller) or 2(Buyer): ";
    cin >> user;
    string filename = "products.txt";
    vector<Product> products;
    read_products(filename, products);
    while(user<=2)
    {
        if (user == 1) 
        {
        
        //for-each loop
        //for(Type element-name : collection-name)
        // for (Product product : products) {
        //     cout << product.name << " " << product.price << " " << product.quantity << endl;
        // }
        seller(products);

        } 
        else if (user == 2) 
        {
            vector<Cart> cart;
            buyer(products,cart);

        } 
        else 
        {
            cout << "Invalid\n";
        }
        cout << "Enter 1(Seller) or 2(Buyer): ";
        cin >> user;
    }

    cout<<"Invalid choice"<<endl;
    return 0;
    
    
}
