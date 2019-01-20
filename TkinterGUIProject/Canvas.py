from tkinter import *

root = Tk()

#Creating a canvas:
canvas = Canvas(root)
canvas.pack()

#Creating a line inside the canvas:
line = canvas.create_line(0, 0, 200, 300, fill = 'blue', width = 3)

#To configure the properties of the line:
canvas.itemconfigure(line, fill = 'green')

#To get or change the coordinates of the line:
canvas.coords(line)
canvas.coords(20, 20, 150, 150, 300, 300) #This sets up two lines

#To change the smoothness of the line:
canvas.itemconfigure(line, smooth = True)
canvas.itemconfigure(splinesteps = 100)

#To delete the line:
canvas.delete(line)

#Creating other shapes in the canvas:
rect = canvas.create_rectangle(200, 200, 500, 500, fill = 'red')
oval = canvas.create_oval(200, 200, 500, 500, fill = 'yellow')
arc = canvas.create_arc(200, 0, 500, 0)
canvas.itemconfigure(arc, fill = 'black')

