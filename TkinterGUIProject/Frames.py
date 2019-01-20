from tkinter import *
from tkinter import ttk

root = Tk()

#Creating a Frame:
frame = ttk.Frame(root)
frame.pack()
frame.config(height = 100, width = 200)
frame.config(relief = RIDGE)        #Sets the type of border of the frame


#Adding a button to the frame
ttk.Button(frame, text = 'Click Me').grid(row = 2, column = 2)

#To add a padding border around the frame:
frame.config(padding = (30, 15))

#Creating a Label Frame to display text:
ttk.LabelFrame(root, height = 100, width = 200, text = 'This is a Label Frame').pack()
