from tkinter import *
from tkinter import ttk

#Creating a Button in the Tk window
root = Tk()
button = ttk.Button(root, text = 'Click Me')
button.pack()

#Managing the button events
def button_event():
    print('The button is clicked.')
button.config(command = button_event)

button.invoke()     #Shows the command of the button and the value that is returned after it
                    #is clicked

button.state(['disabled'])      #To change the state of the button to disabled

button.state(['!disabled'])     #To change the state of the button to enabled


button.instate(['disabled'])    #Returns 'True' if the button is in disabled state

#Adding an image to the button:
#button_img = PhotoImage('#Location of the Image')
#button.config(image = button_img, compound = LEFT/RIGHT/CENTER)

#To create a small sample of the button_img

#small_button = button_img.subsample(x, y)  where x and y are the pixels upto which the image
#considers
