#!/usr/bin/env python
import rospy
from std_msgs.msg import Int32

rospy.init_node('talker_nums')
pub = rospy.Publisher('my_chat_topic', Int32, queue_size=10)
rate = rospy.Rate(10)

def start_talker():
    num = 0
    while not rospy.is_shutdown():
    	
        #hello_str = "hi =) %s" % rospy.get_time()
        rospy.loginfo(num)
        num += 2
        
        pub.publish(num)

        rate.sleep()

try:
    start_talker()
except (rospy.ROSInterruptException, KeyboardInterrupt):
    rospy.logerr('Exception catched')