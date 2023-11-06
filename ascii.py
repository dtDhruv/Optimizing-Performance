import pyfiglet
from termcolor import colored
import shutil

# Function to center the text
def center_text(text):
    terminal_width = shutil.get_terminal_size().columns
    padding = (terminal_width - len(text.split('\n')[0])) // 2
    centered_text = "\n".join([" " * padding + line for line in text.split('\n')])
    return centered_text

result = pyfiglet.figlet_format("Need For Speed", font="slant")
credits = pyfiglet.figlet_format("Credits:")
name1 = pyfiglet.figlet_format("Your Name")
dash = "============================================================================================================================================================"

result_colored = colored(center_text(result), color="cyan", attrs=["bold"])
credits_colored = colored(center_text(credits), color="yellow", attrs=["bold"])
name1_colored = colored(center_text(name1), color="blue", attrs=["bold"])
dash_colored = colored(center_text(dash), color="green")

print(dash_colored)
print(result_colored)
print(credits_colored)
print(dash_colored)
print(name1_colored)
print(dash_colored)
