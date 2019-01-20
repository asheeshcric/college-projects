from tkinter import *
from tkinter import ttk

root = Tk()

#Creating an Entry Field
entry = ttk.Entry(root, width = 50)
entry.pack()

entry.get()     #Gets the string written in the entry box
entry.delete(0,5)   #Deletes the content of the field from 0th to 4th character
entry.delete(0, END)    #Deletes everything in the box
entry.insert(0, 'I am being inserted')  #Inserts string at a particular position
entry.config(show = '*')        #Used to hide the content of the box with a specific character
entry.state(['disabled'])       #Restricts you from entering the text in the box
entry.state(['readonly'])       #Allows the user to only copy the data from the box