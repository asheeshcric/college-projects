from tkinter import *
from tkinter import ttk

root = Tk()

#Creating a Comobbox
month = StringVar()
combobox = ttk.Combobox(root, text = 'Month', textvariable = month)
combobox.pack()
combobox.config(values = ('Jan', 'Feb', 'Mar', 'Nov'))
month.get()

#Creating a Spin Box
year = StringVar()
spinbox = Spinbox(root, text = 'Year', textvariable = year)
spinbox.pack()
spinbox.config(from_ = 1970, to = 2016)
year.get()
