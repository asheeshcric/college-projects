from tkinter import *

root = Tk()

#Creating a menubar:
menubar = Menu(root)
root.option_add('*tearoff', False)  #Removing the default tearoff option for the menubar

#Creating members of the menubar
file = Menu(menubar)
edit = Menu(menubar)
help_ = Menu(menubar)

#Adding titles to the menubar:
menubar.add_cascade(menu = file, label = 'File')
menubar.add_cascade(menu = edit, label = 'Edit')
menubar.add_cascade(menu = help_, label = 'Help')

#Creating commands inside the titles:
file.add_command(label = 'New', command = lambda: print('New File'))
file.add_command(label = 'Open',command = lambda: print('Opening File'))

edit.add_command(label = 'Edit Options', command = lambda: print('Editing Options'))

help_.add_command(label = 'Help Options', command = lambda: print('Help Options'))

#Creating a sub_title inside a title:
save = Menu(file)
file.config(menu = save, label = 'Save')
