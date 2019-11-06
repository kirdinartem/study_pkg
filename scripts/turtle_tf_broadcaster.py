#!/usr/bin/env python
import rospy
import tf
from math import cos
from math import sin
from tf.transformations import quaternion_from_euler
from turtlesim.msg import Pose

# Register node / fake node name - we will rename =)
rospy.init_node('tf_turtle')
# Get private parameter / make it global variable
turtlename = rospy.get_param('~turtle_tf_name')

angl = 0
# Callback function
def handle_turtle_pose(msg):
    # Get broadcaster object
    br = tf.TransformBroadcaster()
    # Broadcast TF trasform (world -> turtlename)
    br.sendTransform((msg.x, msg.y, 0),
                     quaternion_from_euler(0, 0, msg.theta),
                     rospy.Time.now(),
                     turtlename,
                     "world")
    global angl
    if angl < 6.28:
        angl+=0.1
    else:
        angl = 0
    br.sendTransform((sin(angl), cos(angl), 0),
                     quaternion_from_euler(0, 0, msg.theta),
                     rospy.Time.now(),
                     "sattelite",
                     turtlename)

# Subscribe to /input_pose topic - just gonna remap it to work with
rospy.Subscriber('input_pose',
                 Pose,
                 handle_turtle_pose)
# You spin my head right round, right round - Florida =)
# Just handle all topic messages until node (or ROS) is working
rospy.spin()