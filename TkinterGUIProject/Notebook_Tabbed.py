from tkinter import *
from tkinter import ttk

root = Tk()

notebook = ttk.Notebook(root)
notebook.pack()

frame1 = ttk.Frame(notebook)
frame2 = ttk.Frame(notebook)
frame3 = ttk.Frame(notebook)

#Adding tabs to the notebook:
notebook.add(frame1, text = 'Tab 1')
notebook.add(frame3, text = 'Tab 3')

#Inserting  a tab in the notebook:
notebook.insert(1, frame2, text = 'Tab 2')

#To remove any tab:
#notebook.forget(1)         where 1 is the index

notebook.select()   #Gives the id of the tab selected in the GUI
notebook.index(notebook.select())       #Gives the index of the tab selected

#To change the state of a Tab:
notebook.tab(1, state = 'disabled')
notebook.tab(1, state = 'hidden')
notebook.tab(1, state = 'normal')

#To get any property of a tab:
notebook.tab(1, 'text')     #Gives 'Tab 2'
notebook.tab(1)              #Shows the list of all the properties of 'Tab 2' with their values

label1 = ttk.Label(frame1, text = 'TAB NO. 1')
label2 = ttk.Label(frame2, text = 'TAB NO. 2')
label3 = ttk.Label(frame3, text = 'TAB NO. 3')

label1.pack()
label2.pack()
label3.pack()

def b1():
    label1.config(text = 'You pressed button no. 1')

def b2():
    label2.config(text = 'You pressed button no. 2')

def b3():
    label3.config(text = 'You pressed button no. 3')
#Inserting a widget in a tab:
ttk.Button(frame1, text = 'Button1', command = b1).pack()
ttk.Button(frame2, text = 'Button2', command = b2).pack()
ttk.Button(frame3, text = 'Button3', command = b3).pack()

