from tkinter import *
from tkinter import ttk

root = Tk()

#Creating a Progressbar
progress = ttk.Progressbar(root, orient = HORIZONTAL, length = 200)
progress.pack()

#Indeteminate Mode of Progressbar:
progress.config(mode = 'indeterminate')
progress.start()
progress.stop()

#Determinate Mode of Progressbar:
progress.config(mode = 'determinate', maximum = 10.0)
progress.config(value = 3.5)        #Makes the value of the progressbar to 3.5
progress.step(2)                    #Increases the progress value by 2, i.e it becomes 5.5

#To make the progressbar dependent to a variable:
progress_value = DoubleVar()
progress.config(variable = progress_value)

#Creating a Scale:
scale = ttk.Scale(root, orient = HORIZONTAL, length = 200, variable = progress_value, from_ = 0,
                  to = 10)
scale.pack()

