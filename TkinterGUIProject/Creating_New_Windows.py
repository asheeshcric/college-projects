from tkinter import *

root = Tk()

window = Toplevel(root)     #Creating a new top-level window which is a child of the root window
window.title('New Window')  #Changing the title of the window

#To lower the new window from other windows:
window.lower()

#To lift the window above any window:
window.lift(root)

#To modify the state of the window
#window.state('zoomed')      #Maximizes the size of the window
window.state('withdrawn')   #Disappears the window from the screen
window.state('iconic')      #Moves the window to the taskbar icon
#window.state('normal')      #Brings back the window to the previous state, i.e. zoomed
window.state('normal')      #Brings back the window to the normal (initial) state

#To iconify and deiconify:
window.iconify()
window.deiconify()

#USing a geometry() method to alter the size of the window:
window.geometry('640x480+100+200')  #640*480 = Size in pixels
                                    #100 = pixels distance from left of the screen
                                    #200 = pixels distance from the top of the screen

#To make sure that the window is not resizable we use:
window.resizable(False, False)

#To switch the window back to resizable:
window.resizable(True, True)

#To set the max and min size of the window:
window.maxsize(640, 480)    #In pixels
window.minsize(200, 150)

#To destroy any window along with all its child content:
window.destroy()        #Destroys the new window along with its widgets but not the root window
root.destroy()          #Destroys root along with everything that is a child of the root window
