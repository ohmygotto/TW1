#include <string>
#include <iostream>

using namespace std;

class Item
{
public:
    Item(const std::string& name = "", int price = 0)
        : name_(name), price_(price)
    {
    }

    const std::string& GetName() const
    {
        return name_;
    }

    int GetPrice() const
    {
        return price_;
    }

    void PrintInfo() const
    {
        cout << "[Name: " << name_ << ", Price: " << price_ << "G]" << endl;
    }

private:
    std::string name_;
    int price_;
};

template<typename T>
class Inventory
{
public:
    Inventory(int capacity = 10)
    {
        if (capacity <= 0)
        {
            capacity_ = 1;
        }
        else
        {
            capacity_ = capacity;
        }

        size_ = 0;
        pItems_ = new T[capacity_];
    }

    ~Inventory()
    {
        delete[] pItems_;
        pItems_ = nullptr;
    }

    void AddItem(const T& item)
    {
        if (size_ >= capacity_)
        {
            cout << "Inventory is full!" << endl;
            return;
        }

        pItems_[size_] = item;
        ++size_;
    }

    void RemoveLastItem()
    {
        if (size_ == 0)
        {
            cout << "Inventory is empty." << endl;
            return;
        }

        --size_;
    }

    int GetSize() const
    {
        return size_;
    }

    int GetCapacity() const
    {
        return capacity_;
    }

    void PrintAllItems() const
    {
        if (size_ == 0)
        {
            cout << "Empty" << endl;
            return;
        }

        for (int i = 0; i < size_; ++i)
        {
            pItems_[i].PrintInfo();
        }
    }

private:
    T* pItems_;
    int capacity_;
    int size_;
};

int main()
{
    Inventory<Item> itemInventory(3);

    itemInventory.AddItem(Item("Potion", 100));
    itemInventory.AddItem(Item("Sword", 500));
    itemInventory.AddItem(Item("Shield", 300));

    itemInventory.PrintAllItems();

    cout << "Current Size: " << itemInventory.GetSize() << endl;
    cout << "Max Capacity: " << itemInventory.GetCapacity() << endl;

    itemInventory.AddItem(Item("Bow", 400));

    itemInventory.RemoveLastItem();
    itemInventory.PrintAllItems();

    itemInventory.RemoveLastItem();
    itemInventory.RemoveLastItem();
    itemInventory.RemoveLastItem();

    return 0;
}