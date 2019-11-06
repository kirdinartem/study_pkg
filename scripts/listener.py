#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def callback(msg):
	rospy.loginfo("I hear %s", msg)

rospy.init_node('listener')
rospy.Subscriber('my_chat_topic', String, callback, queue_size = 10)

rospy.spin()