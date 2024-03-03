import pyttsx3
import datetime

engine = pyttsx3.init("sapi5" )
voices = engine.getProperty("voices")
engine.setProperty("voice", voices[0].id)
engine. setProperty ("rate", 170)

def speak(audio):
    engine = pyttsx3.init()
    engine.say(audio)
    engine.runAndWait()

def greeetMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<=12:
        speak("Good Morning, Sir! I am MAVEN A.I.")
    elif hour>12 and hour<=18:
        speak("Good Afternoon, Sir! I am MAVEN A.I.")
    else:
        speak("Good Evening, Sir! I am MAVEN A.I.")

    speak("Please tell me, How can i help you ?")