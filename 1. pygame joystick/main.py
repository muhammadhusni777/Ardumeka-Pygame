
import sys
import threading
import pygame
pygame.init()
#----------------------------------------------------------------#

analog1_x = 0
analog1_y = 0
analog1_x_prev = 0
analog1_y_prev = 0

analog2_x = 0
analog2_y = 0
analog2_x_prev = 0
analog2_y_prev = 0

hat = ""
hat_prev = ""
    

#----------------------------------------------------------------#

def pygame_run():
    global analog1_x
    global analog1_y
    global analog1_x_prev
    global analog1_y_prev

    global analog2_x
    global analog2_y
    global analog2_x_prev
    global analog2_y_prev
    
    global hat
    global hat_prev
    
    
    
    clock = pygame.time.Clock()
    joysticks = {}
    done = False
    while not done:
        # Event processing step.
        # Possible joystick events: JOYAXISMOTION, JOYBALLMOTION, JOYBUTTONDOWN,
        # JOYBUTTONUP, JOYHATMOTION, JOYDEVICEADDED, JOYDEVICEREMOVED
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                done = True  # Flag that we are done so we exit this loop.

            #----------------BUTTON-------------------#
            if event.type == pygame.JOYBUTTONDOWN:
                #print("Joystick button pressed.")
                status_button = "pressed"
                joy_button_status = status_button
                joy_button_event = event.button
                #print(joy_button_status)
                print(joy_button_event)
                
                
                if event.button == 0:
                    
                    joystick = joysticks[event.instance_id]
                    
                
                
           
            if event.type == pygame.JOYBUTTONUP:
                #print("Joystick button released.")
                joy_button_status = status_button
                joy_button_event = event.button
        

            if event.type == pygame.JOYDEVICEADDED:
                # This event will be generated when the program starts for every
                # joystick, filling up the list without needing to create them manually.
                joy = pygame.joystick.Joystick(event.device_index)
                joysticks[joy.get_instance_id()] = joy
                print("Joystick {} connected".format(joy.get_instance_id()))
                

            if event.type == pygame.JOYDEVICEREMOVED:
                del joysticks[event.instance_id]
                print("Joystick {} disconnected".format(event.instance_id))

       
            
        
        for joystick in joysticks.values():
                
            jid = joystick.get_instance_id()
            name = joystick.get_name()
            guid = joystick.get_guid()
            power_level = joystick.get_power_level()
            axes = joystick.get_numaxes()
            
            #----------------axes-------------------#
            for i in range(axes):
                axis = joystick.get_axis(i)
                if i == 0 :
                    analog1_x = axis
                if i == 1 :
                    analog1_y = axis
                if i == 2 :
                    analog2_y = axis
                if i == 3 :
                    analog2_x = axis
                    #print(axis)
                
                a =+ 1
            
            
            
            buttons = joystick.get_numbuttons()
            

            for i in range(buttons):
                button = joystick.get_button(i)
            
            
            #----------------hats-------------------#
            hats = joystick.get_numhats()
            
            
            
            for i in range(hats):
                hat = joystick.get_hat(i)
            
        if (hat != hat_prev):    
            print(hat)
            
                
        hat_prev = hat
        
        if (analog1_x != (analog1_x_prev) ):
            print(analog1_x)
            
        if (analog1_y != (analog1_y_prev) ):
            print(analog1_y)
            
        if (analog2_x != (analog2_x_prev) ):
            print(analog2_x)
            
        if (analog2_y != (analog2_y_prev) ):
            print(analog2_y)
        
        
        
        analog1_x_prev = analog1_x
        analog1_y_prev = analog1_y
        analog2_x_prev = analog2_x
        analog2_y_prev = analog2_y
        
        clock.tick(30)



if __name__ == "__main__":
    pygame_run()

    
    
#----------------------------------------------------------------#