#!/usr/bin/env python

import rospy
from study_pkg.msg import Control

rospy.init_node('talker_to_new_msg')

pub = rospy.Publisher('chatter', Control, queue_size=10)
rate = rospy.Rate(1)

def start():
	msg = Control()
	msg.steer = 0
	msg.speed = 0
	while not rospy.is_shutdown():
		msg.steer += 1
		msg.speed += 2
		rospy.loginfo("steer = %s" %msg.steer)
		rospy.loginfo("speed = %s" %msg.speed)

		pub.publish(msg)

		rate.sleep()

try:
	start()
except (rospy.ROSInterruptException, KeyboardInterrupt):
	rospy.logerr('Exception catched')
