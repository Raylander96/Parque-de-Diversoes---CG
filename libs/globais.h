const int 	SKY_FRONT=0,
			SKY_RIGHT=1,
			SKY_LEFT=2,
			SKY_BACK=3,
			SKY_UP=4,
			SKY_DOWN=5,
			GWHEEL_RING=3,
			GWHEEL_TROLLEY=4, 
			GWHEEL_TOP=5;
			


int 	ni=0,
		prevx=0, 
		rcam=1,
		bezno,
		camw=0, 
		roll=1, 
		background=0, 
		cswing=1, 
		gw=1,
		gwheel_ring_color=0, 
		gwheel_trolley_color=0,
		fog=0;

GLint 	skybox[6], 
		floor_park,
		help=0,
		x_r=0, 
		y_r=0, 
		z_r=0;

GLfloat viewer[3] = {1.0f, 0.0f, 0.0f},
		camera[3] = {0.0f, 0.0, 0.0};

GLdouble 	curr=0, 
			prev=0,
			gw_spin = 0.0,
			angle=0.0,
			c_angle=90.0,
			gw_width = 8.0, 
			gw_radius=45.0,
			gw_x=-180.0, 
			gw_y=50.0, 
			gw_z=220.0,
			co_x=180.0, 
			co_y=0.0, 
			co_z=80.0,
			lx=50.0,
			ly=50.0,
			lz=50.0,
			gy=0,
			movcord[3]={-150,-10,200};
			

Mix_Music *theme = NULL;
