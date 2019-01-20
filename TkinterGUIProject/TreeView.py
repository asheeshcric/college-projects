from tkinter import *
from tkinter import ttk

root = Tk()

treeview = ttk.Treeview(root)
treeview.pack()

#Inserting items to the tree view:
treeview.insert('', '0', 'item1', text = 'First Item')  #insert('blank  string', 'position',
                                                        # 'item_name', text
treeview.insert('', '1', 'item2', text = 'Second Item')
treeview.insert('', 'end', 'item3', text = 'Last Item')

#Adding a member with image to any of the items:
logo = PhotoImage(file = '/home/asheesh/Desktop/python_logo.gif').subsample(10, 10)

treeview.insert('item2', 'end', 'new_item', text = 'New Item')

treeview.config(height = 5)

#Moving an item under another item:
treeview.move('item2', 'item1', 'end')  #Moves item2 under item1

#To detach any item:
treeview.detach('item3')    #Makes the item disappear but does not delete it from the treeview

treeview.move('item3', 'item2', '0')
