from tkinter import *
from tkinter import ttk

root = Tk()

panedwindow = ttk.Panedwindow(root, orient = HORIZONTAL)
panedwindow.pack(fill = BOTH, expand = True)

frame1 = ttk.Frame(panedwindow, width = 200, height = 300, relief = SUNKEN)
frame2 = ttk.Frame(panedwindow, width = 300, height = 300, relief = RIDGE)
frame3 = ttk.Frame(panedwindow, width = 400, height = 300, relief = SUNKEN)

#Adding frames to the PanedWindow
panedwindow.add(frame1, weight = 2) #Weight defines the ratio by which the frame size increases
panedwindow.add(frame2, weight = 1)

#Inserting a frame in the panedwindow:
panedwindow.insert(1, frame3)   #Where 1 is the index where the frame is inserted. 0 is the first
                                #position and 1 is the second position

#To remove any frame from the PanedWindow:
panedwindow.forget(1)   #where 1 is the index of the frame


