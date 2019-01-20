from tkinter import *
from tkinter import ttk

root = Tk()

malebutton = ttk.Checkbutton(root, text='Male')
femalebutton = ttk.Checkbutton(root, text='Female')

malebutton.pack()
femalebutton.pack()

# Creating a variable in Tkinter

gender = StringVar()  # Makes gender a string variable
gender.set('I determine the sex of a person')  # Assigning string to the variable
gender.get()  # Getting the value of the variable

# To assign the string variable with the check buttons

malebutton.config(variable=gender, onvalue='I am Male', offvalue='I am female')
femalebutton.config(variable=gender, onvalue='I am Female', offvalue='I am male')

gender.get()

# Creating Radio Buttons

breakfast = StringVar()
breakfast.set('I am your choice')
print(breakfast.get())

ttk.Radiobutton(root, text='Eggs', variable=breakfast, value='I want Eggs').pack()
ttk.Radiobutton(root, text='Breads', variable=breakfast, value='I want Breads').pack()
ttk.Radiobutton(root, text='Daal', variable=breakfast, value='I want Daal').pack()
ttk.Radiobutton(root, text='Sandwich', variable=breakfast, value='I want Sandwich').pack()

print(breakfast.get())
root.mainloop()



