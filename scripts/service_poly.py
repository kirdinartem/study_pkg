#!/usr/bin/env python

import rospy
from study_pkg.srv import Poly, PolyRequest, PolyResponse

rospy.wait_for_service('poly')

try:
    poly_srv = rospy.ServiceProxy('poly', Poly)
    req = PolyRequest(x=15)
    resp = poly_srv(req)

    rospy.loginfo('Response: %s' % resp.y)
except rospy.ServiceException, e:
    rospy.logerr("Service call failed: %s" % e)