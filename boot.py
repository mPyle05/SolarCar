import cv2
import numpy as np

# Constants
DEBUGMODE = False
WINDOW_WIDTH, WINDOW_HEIGHT = 800, 450
STATS_WIDTH = 225
FONT, FONT_SIZE, LARGE_FONT_SIZE = cv2.FONT_HERSHEY_SIMPLEX, 1, 2
TEXT_COLOR = (0, 0, 0)  
THICKNESS = 2
ITEM_HEIGHT, STAT_OFFSET = 50, 35

# Video Capture
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Error opening video stream or file")
    exit()

if not DEBUGMODE:
    cv2.namedWindow("window", cv2.WINDOW_NORMAL)
    cv2.setWindowProperty("window", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)

# Data Retrieval Functions
def get_mph(): 
    return 30
def get_motor_temp(): 
    return 100
def get_battery_temp(): 
    return 60
def get_battery_pct(): 
    return 75

# Function to Overlay Horizontally Centered Text
def add_text_line(image, text, line_number, large=False):
    font_size = LARGE_FONT_SIZE if large else FONT_SIZE
    text_size = cv2.getTextSize(text, FONT, font_size, THICKNESS)[0]
    text_width = text_size[0]

    # Calculate centered X position
    x_position = (STATS_WIDTH - text_width) // 2  
    y_position = STAT_OFFSET + (line_number * ITEM_HEIGHT)

    return cv2.putText(image, text, (x_position, y_position), FONT, font_size, TEXT_COLOR, THICKNESS, cv2.LINE_AA)

# Generate Stats Display
def get_stats_display():
    base_image = np.full((WINDOW_HEIGHT, STATS_WIDTH, 3), 255, dtype=np.uint8)
    
    base_image = add_text_line(base_image, 'MPH', 0)
    base_image = add_text_line(base_image, str(get_mph()), 1, large=True)
    
    base_image = add_text_line(base_image, 'Motor Temp', 2)
    base_image = add_text_line(base_image, str(get_motor_temp()), 3, large=True)
    
    base_image = add_text_line(base_image, 'Bat Temp', 4)
    base_image = add_text_line(base_image, str(get_battery_temp()), 5, large=True)
    
    base_image = add_text_line(base_image, 'Bat %', 6)
    base_image = add_text_line(base_image, str(get_battery_pct()), 7, large=True)
    
    return base_image

# Main Loop
while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    frame = cv2.resize(frame, (WINDOW_WIDTH - STATS_WIDTH, WINDOW_HEIGHT))
    combined_frame = np.hstack((get_stats_display(), frame))

    cv2.imshow('window', combined_frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):  # More responsive exit
        break

cap.release()
cv2.destroyAllWindows()