#Creating a Widget with a Button and a Label


from tkinter import *
from tkinter import ttk

root = Tk()
button = ttk.Button(root, text = 'Click Me')
button.pack()

ttk.Label(root, text = "I am new to Tkinter").pack()
