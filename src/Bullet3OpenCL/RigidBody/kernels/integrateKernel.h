//this file is autogenerated using stringify.bat (premake --stringify) in the build folder of this project
static const char* integrateKernelCL= \
"/*\n"
"Copyright (c) 2013 Advanced Micro Devices, Inc.  \n"
"This software is provided 'as-is', without any express or implied warranty.\n"
"In no event will the authors be held liable for any damages arising from the use of this software.\n"
"Permission is granted to anyone to use this software for any purpose, \n"
"including commercial applications, and to alter it and redistribute it freely, \n"
"subject to the following restrictions:\n"
"1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.\n"
"2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.\n"
"3. This notice may not be removed or altered from any source distribution.\n"
"*/\n"
"//Originally written by Erwin Coumans\n"
"#ifndef B3_RIGIDBODY_DATA_H\n"
"#define B3_RIGIDBODY_DATA_H\n"
"#ifndef B3_FLOAT4_H\n"
"#define B3_FLOAT4_H\n"
"#ifndef B3_PLATFORM_DEFINITIONS_H\n"
"#define B3_PLATFORM_DEFINITIONS_H\n"
"struct MyTest\n"
"{\n"
"	int bla;\n"
"};\n"
"#ifdef __cplusplus\n"
"#else\n"
"#define b3AtomicInc atomic_inc\n"
"#define b3Fabs fabs\n"
"#define b3Sqrt native_sqrt\n"
"#define b3Sin native_sin\n"
"#define b3Cos native_cos\n"
"#endif\n"
"#endif\n"
"#ifdef __cplusplus\n"
"#else\n"
"	typedef float4	b3Float4;\n"
"	#define b3Float4ConstArg const b3Float4\n"
"	#define b3MakeFloat4 (float4)\n"
"	float b3Dot3F4(b3Float4ConstArg v0,b3Float4ConstArg v1)\n"
"	{\n"
"		float4 a1 = b3MakeFloat4(v0.xyz,0.f);\n"
"		float4 b1 = b3MakeFloat4(v1.xyz,0.f);\n"
"		return dot(a1, b1);\n"
"	}\n"
"	b3Float4 b3Cross3(b3Float4ConstArg v0,b3Float4ConstArg v1)\n"
"	{\n"
"		float4 a1 = b3MakeFloat4(v0.xyz,0.f);\n"
"		float4 b1 = b3MakeFloat4(v1.xyz,0.f);\n"
"		return cross(a1, b1);\n"
"	}\n"
"#endif \n"
"		\n"
"inline bool b3IsAlmostZero(b3Float4ConstArg v)\n"
"{\n"
"	if(b3Fabs(v.x)>1e-6 || b3Fabs(v.y)>1e-6 || b3Fabs(v.z)>1e-6)	\n"
"		return false;\n"
"	return true;\n"
"}\n"
"#endif //B3_FLOAT4_H\n"
"#ifndef B3_QUAT_H\n"
"#define B3_QUAT_H\n"
"#ifndef B3_PLATFORM_DEFINITIONS_H\n"
"#ifdef __cplusplus\n"
"#else\n"
"#endif\n"
"#endif\n"
"#ifndef B3_FLOAT4_H\n"
"#ifdef __cplusplus\n"
"#else\n"
"#endif \n"
"#endif //B3_FLOAT4_H\n"
"#ifdef __cplusplus\n"
"#else\n"
"	typedef float4	b3Quat;\n"
"	#define b3QuatConstArg const b3Quat\n"
"	\n"
"	\n"
"inline float4 b3FastNormalize4(float4 v)\n"
"{\n"
"	v = (float4)(v.xyz,0.f);\n"
"	return fast_normalize(v);\n"
"}\n"
"	\n"
"inline b3Quat b3QuatMul(b3Quat a, b3Quat b);\n"
"inline b3Quat b3QuatNormalized(b3QuatConstArg in);\n"
"inline b3Quat b3QuatRotate(b3QuatConstArg q, b3QuatConstArg vec);\n"
"inline b3Quat b3QuatInvert(b3QuatConstArg q);\n"
"inline b3Quat b3QuatMul(b3QuatConstArg a, b3QuatConstArg b)\n"
"{\n"
"	b3Quat ans;\n"
"	ans = b3Cross3( a, b );\n"
"	ans += a.w*b+b.w*a;\n"
"//	ans.w = a.w*b.w - (a.x*b.x+a.y*b.y+a.z*b.z);\n"
"	ans.w = a.w*b.w - b3Dot3F4(a, b);\n"
"	return ans;\n"
"}\n"
"inline b3Quat b3QuatNormalized(b3QuatConstArg in)\n"
"{\n"
"	b3Quat q;\n"
"	q=in;\n"
"	//return b3FastNormalize4(in);\n"
"	float len = native_sqrt(dot(q, q));\n"
"	if(len > 0.f)\n"
"	{\n"
"		q *= 1.f / len;\n"
"	}\n"
"	else\n"
"	{\n"
"		q.x = q.y = q.z = 0.f;\n"
"		q.w = 1.f;\n"
"	}\n"
"	return q;\n"
"}\n"
"inline float4 b3QuatRotate(b3QuatConstArg q, b3QuatConstArg vec)\n"
"{\n"
"	b3Quat qInv = b3QuatInvert( q );\n"
"	float4 vcpy = vec;\n"
"	vcpy.w = 0.f;\n"
"	float4 out = b3QuatMul(b3QuatMul(q,vcpy),qInv);\n"
"	return out;\n"
"}\n"
"inline b3Quat b3QuatInvert(b3QuatConstArg q)\n"
"{\n"
"	return (b3Quat)(-q.xyz, q.w);\n"
"}\n"
"inline float4 b3QuatInvRotate(b3QuatConstArg q, b3QuatConstArg vec)\n"
"{\n"
"	return b3QuatRotate( b3QuatInvert( q ), vec );\n"
"}\n"
"inline b3Float4 b3TransformPoint(b3Float4ConstArg point, b3Float4ConstArg translation, b3QuatConstArg  orientation)\n"
"{\n"
"	return b3QuatRotate( orientation, point ) + (translation);\n"
"}\n"
"	\n"
"#endif \n"
"#endif //B3_QUAT_H\n"
"#ifndef B3_MAT3x3_H\n"
"#define B3_MAT3x3_H\n"
"#ifndef B3_QUAT_H\n"
"#ifdef __cplusplus\n"
"#else\n"
"#endif \n"
"#endif //B3_QUAT_H\n"
"#ifdef __cplusplus\n"
"#else\n"
"typedef struct\n"
"{\n"
"	b3Float4 m_row[3];\n"
"}b3Mat3x3;\n"
"#define b3Mat3x3ConstArg const b3Mat3x3\n"
"#define b3GetRow(m,row) (m.m_row[row])\n"
"inline b3Mat3x3 b3QuatGetRotationMatrix(b3Quat quat)\n"
"{\n"
"	b3Float4 quat2 = (b3Float4)(quat.x*quat.x, quat.y*quat.y, quat.z*quat.z, 0.f);\n"
"	b3Mat3x3 out;\n"
"	out.m_row[0].x=1-2*quat2.y-2*quat2.z;\n"
"	out.m_row[0].y=2*quat.x*quat.y-2*quat.w*quat.z;\n"
"	out.m_row[0].z=2*quat.x*quat.z+2*quat.w*quat.y;\n"
"	out.m_row[0].w = 0.f;\n"
"	out.m_row[1].x=2*quat.x*quat.y+2*quat.w*quat.z;\n"
"	out.m_row[1].y=1-2*quat2.x-2*quat2.z;\n"
"	out.m_row[1].z=2*quat.y*quat.z-2*quat.w*quat.x;\n"
"	out.m_row[1].w = 0.f;\n"
"	out.m_row[2].x=2*quat.x*quat.z-2*quat.w*quat.y;\n"
"	out.m_row[2].y=2*quat.y*quat.z+2*quat.w*quat.x;\n"
"	out.m_row[2].z=1-2*quat2.x-2*quat2.y;\n"
"	out.m_row[2].w = 0.f;\n"
"	return out;\n"
"}\n"
"inline b3Mat3x3 b3AbsoluteMat3x3(b3Mat3x3ConstArg matIn)\n"
"{\n"
"	b3Mat3x3 out;\n"
"	out.m_row[0] = fabs(matIn.m_row[0]);\n"
"	out.m_row[1] = fabs(matIn.m_row[1]);\n"
"	out.m_row[2] = fabs(matIn.m_row[2]);\n"
"	return out;\n"
"}\n"
"__inline\n"
"b3Mat3x3 mtZero();\n"
"__inline\n"
"b3Mat3x3 mtIdentity();\n"
"__inline\n"
"b3Mat3x3 mtTranspose(b3Mat3x3 m);\n"
"__inline\n"
"b3Mat3x3 mtMul(b3Mat3x3 a, b3Mat3x3 b);\n"
"__inline\n"
"b3Float4 mtMul1(b3Mat3x3 a, b3Float4 b);\n"
"__inline\n"
"b3Float4 mtMul3(b3Float4 a, b3Mat3x3 b);\n"
"__inline\n"
"b3Mat3x3 mtZero()\n"
"{\n"
"	b3Mat3x3 m;\n"
"	m.m_row[0] = (b3Float4)(0.f);\n"
"	m.m_row[1] = (b3Float4)(0.f);\n"
"	m.m_row[2] = (b3Float4)(0.f);\n"
"	return m;\n"
"}\n"
"__inline\n"
"b3Mat3x3 mtIdentity()\n"
"{\n"
"	b3Mat3x3 m;\n"
"	m.m_row[0] = (b3Float4)(1,0,0,0);\n"
"	m.m_row[1] = (b3Float4)(0,1,0,0);\n"
"	m.m_row[2] = (b3Float4)(0,0,1,0);\n"
"	return m;\n"
"}\n"
"__inline\n"
"b3Mat3x3 mtTranspose(b3Mat3x3 m)\n"
"{\n"
"	b3Mat3x3 out;\n"
"	out.m_row[0] = (b3Float4)(m.m_row[0].x, m.m_row[1].x, m.m_row[2].x, 0.f);\n"
"	out.m_row[1] = (b3Float4)(m.m_row[0].y, m.m_row[1].y, m.m_row[2].y, 0.f);\n"
"	out.m_row[2] = (b3Float4)(m.m_row[0].z, m.m_row[1].z, m.m_row[2].z, 0.f);\n"
"	return out;\n"
"}\n"
"__inline\n"
"b3Mat3x3 mtMul(b3Mat3x3 a, b3Mat3x3 b)\n"
"{\n"
"	b3Mat3x3 transB;\n"
"	transB = mtTranspose( b );\n"
"	b3Mat3x3 ans;\n"
"	//	why this doesn't run when 0ing in the for{}\n"
"	a.m_row[0].w = 0.f;\n"
"	a.m_row[1].w = 0.f;\n"
"	a.m_row[2].w = 0.f;\n"
"	for(int i=0; i<3; i++)\n"
"	{\n"
"//	a.m_row[i].w = 0.f;\n"
"		ans.m_row[i].x = b3Dot3F4(a.m_row[i],transB.m_row[0]);\n"
"		ans.m_row[i].y = b3Dot3F4(a.m_row[i],transB.m_row[1]);\n"
"		ans.m_row[i].z = b3Dot3F4(a.m_row[i],transB.m_row[2]);\n"
"		ans.m_row[i].w = 0.f;\n"
"	}\n"
"	return ans;\n"
"}\n"
"__inline\n"
"b3Float4 mtMul1(b3Mat3x3 a, b3Float4 b)\n"
"{\n"
"	b3Float4 ans;\n"
"	ans.x = b3Dot3F4( a.m_row[0], b );\n"
"	ans.y = b3Dot3F4( a.m_row[1], b );\n"
"	ans.z = b3Dot3F4( a.m_row[2], b );\n"
"	ans.w = 0.f;\n"
"	return ans;\n"
"}\n"
"__inline\n"
"b3Float4 mtMul3(b3Float4 a, b3Mat3x3 b)\n"
"{\n"
"	b3Float4 colx = b3MakeFloat4(b.m_row[0].x, b.m_row[1].x, b.m_row[2].x, 0);\n"
"	b3Float4 coly = b3MakeFloat4(b.m_row[0].y, b.m_row[1].y, b.m_row[2].y, 0);\n"
"	b3Float4 colz = b3MakeFloat4(b.m_row[0].z, b.m_row[1].z, b.m_row[2].z, 0);\n"
"	b3Float4 ans;\n"
"	ans.x = b3Dot3F4( a, colx );\n"
"	ans.y = b3Dot3F4( a, coly );\n"
"	ans.z = b3Dot3F4( a, colz );\n"
"	return ans;\n"
"}\n"
"#endif\n"
"#endif //B3_MAT3x3_H\n"
"typedef struct b3RigidBodyData b3RigidBodyData_t;\n"
"struct b3RigidBodyData\n"
"{\n"
"	b3Float4				m_pos;\n"
"	b3Quat					m_quat;\n"
"	b3Float4				m_linVel;\n"
"	b3Float4				m_angVel;\n"
"	int 					m_collidableIdx;\n"
"	float 				m_invMass;\n"
"	float 				m_restituitionCoeff;\n"
"	float 				m_frictionCoeff;\n"
"};\n"
"typedef struct b3InertiaData b3InertiaData_t;\n"
"struct b3InertiaData\n"
"{\n"
"	b3Mat3x3 m_invInertiaWorld;\n"
"	b3Mat3x3 m_initInvInertia;\n"
"};\n"
"#endif //B3_RIGIDBODY_DATA_H\n"
"	\n"
"#ifndef B3_RIGIDBODY_DATA_H\n"
"#endif //B3_RIGIDBODY_DATA_H\n"
"	\n"
"inline void integrateSingleTransform( __global b3RigidBodyData_t* bodies,int nodeID, float timeStep, float angularDamping, b3Float4ConstArg gravityAcceleration)\n"
"{\n"
"	\n"
"	if (bodies[nodeID].m_invMass != 0.f)\n"
"	{\n"
"		float BT_GPU_ANGULAR_MOTION_THRESHOLD = (0.25f * 3.14159254f);\n"
"		//angular velocity\n"
"		{\n"
"			b3Float4 axis;\n"
"			//add some hardcoded angular damping\n"
"			bodies[nodeID].m_angVel.x *= angularDamping;\n"
"			bodies[nodeID].m_angVel.y *= angularDamping;\n"
"			bodies[nodeID].m_angVel.z *= angularDamping;\n"
"			\n"
"			b3Float4 angvel = bodies[nodeID].m_angVel;\n"
"			float fAngle = b3Sqrt(b3Dot3F4(angvel, angvel));\n"
"			\n"
"			//limit the angular motion\n"
"			if(fAngle*timeStep > BT_GPU_ANGULAR_MOTION_THRESHOLD)\n"
"			{\n"
"				fAngle = BT_GPU_ANGULAR_MOTION_THRESHOLD / timeStep;\n"
"			}\n"
"			if(fAngle < 0.001f)\n"
"			{\n"
"				// use Taylor's expansions of sync function\n"
"				axis = angvel * (0.5f*timeStep-(timeStep*timeStep*timeStep)*0.020833333333f * fAngle * fAngle);\n"
"			}\n"
"			else\n"
"			{\n"
"				// sync(fAngle) = sin(c*fAngle)/t\n"
"				axis = angvel * ( b3Sin(0.5f * fAngle * timeStep) / fAngle);\n"
"			}\n"
"			\n"
"			b3Quat dorn;\n"
"			dorn.x = axis.x;\n"
"			dorn.y = axis.y;\n"
"			dorn.z = axis.z;\n"
"			dorn.w = b3Cos(fAngle * timeStep * 0.5f);\n"
"			b3Quat orn0 = bodies[nodeID].m_quat;\n"
"			b3Quat predictedOrn = b3QuatMul(dorn, orn0);\n"
"			predictedOrn = b3QuatNormalized(predictedOrn);\n"
"			bodies[nodeID].m_quat=predictedOrn;\n"
"		}\n"
"		//linear velocity		\n"
"		bodies[nodeID].m_pos +=  bodies[nodeID].m_linVel * timeStep;\n"
"		\n"
"		//apply gravity\n"
"		bodies[nodeID].m_linVel += gravityAcceleration * timeStep;\n"
"		\n"
"	}\n"
"	\n"
"}\n"
"inline void b3IntegrateTransform( __global b3RigidBodyData_t* body, float timeStep, float angularDamping, b3Float4ConstArg gravityAcceleration)\n"
"{\n"
"	float BT_GPU_ANGULAR_MOTION_THRESHOLD = (0.25f * 3.14159254f);\n"
"	\n"
"	if( (body->m_invMass != 0.f))\n"
"	{\n"
"		//angular velocity\n"
"		{\n"
"			b3Float4 axis;\n"
"			//add some hardcoded angular damping\n"
"			body->m_angVel.x *= angularDamping;\n"
"			body->m_angVel.y *= angularDamping;\n"
"			body->m_angVel.z *= angularDamping;\n"
"			\n"
"			b3Float4 angvel = body->m_angVel;\n"
"			float fAngle = b3Sqrt(b3Dot3F4(angvel, angvel));\n"
"			//limit the angular motion\n"
"			if(fAngle*timeStep > BT_GPU_ANGULAR_MOTION_THRESHOLD)\n"
"			{\n"
"				fAngle = BT_GPU_ANGULAR_MOTION_THRESHOLD / timeStep;\n"
"			}\n"
"			if(fAngle < 0.001f)\n"
"			{\n"
"				// use Taylor's expansions of sync function\n"
"				axis = angvel * (0.5f*timeStep-(timeStep*timeStep*timeStep)*0.020833333333f * fAngle * fAngle);\n"
"			}\n"
"			else\n"
"			{\n"
"				// sync(fAngle) = sin(c*fAngle)/t\n"
"				axis = angvel * ( b3Sin(0.5f * fAngle * timeStep) / fAngle);\n"
"			}\n"
"			b3Quat dorn;\n"
"			dorn.x = axis.x;\n"
"			dorn.y = axis.y;\n"
"			dorn.z = axis.z;\n"
"			dorn.w = b3Cos(fAngle * timeStep * 0.5f);\n"
"			b3Quat orn0 = body->m_quat;\n"
"			b3Quat predictedOrn = b3QuatMul(dorn, orn0);\n"
"			predictedOrn = b3QuatNormalized(predictedOrn);\n"
"			body->m_quat=predictedOrn;\n"
"		}\n"
"		//apply gravity\n"
"		body->m_linVel += gravityAcceleration * timeStep;\n"
"		//linear velocity		\n"
"		body->m_pos +=  body->m_linVel * timeStep;\n"
"		\n"
"	}\n"
"	\n"
"}\n"
"__kernel void \n"
"  integrateTransformsKernel( __global b3RigidBodyData_t* bodies,const int numNodes, float timeStep, float angularDamping, float4 gravityAcceleration)\n"
"{\n"
"	int nodeID = get_global_id(0);\n"
"	\n"
"	if( nodeID < numNodes)\n"
"	{\n"
"		integrateSingleTransform(bodies,nodeID, timeStep, angularDamping,gravityAcceleration);\n"
"	}\n"
"}\n"
;
