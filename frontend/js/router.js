// ============================================
// Client-Side Router
// ============================================

const Router = {
    routes: {},
    currentRoute: null,

    /**
     * Define a route
     * @param {string} path - Route path
     * @param {Function} handler - Route handler function
     */
    register(path, handler) {
        this.routes[path] = handler;
    },

    /**
     * Navigate to a route
     * @param {string} path - Route path
     * @param {Object} params - Route parameters
     */
    navigate(path, params = {}) {
        // Check authentication
        if (path !== 'login' && !State.isAuthenticated()) {
            path = 'login';
        }

        this.currentRoute = path;
        State.currentRoute = path;

        // Update URL hash
        window.location.hash = path;

        // Execute route handler
        if (this.routes[path]) {
            this.routes[path](params);
        } else {
            console.error(`Route not found: ${path}`);
        }

        // Update active nav links
        this.updateActiveNavLinks(path);
    },

    /**
     * Update active navigation links
     * @param {string} currentPath
     */
    updateActiveNavLinks(currentPath) {
        document.querySelectorAll('.nav-link').forEach(link => {
            const linkPath = link.getAttribute('data-route');
            if (linkPath === currentPath) {
                link.classList.add('active');
            } else {
                link.classList.remove('active');
            }
        });
    },

    /**
     * Initialize router
     */
    init() {
        // Handle hash change
        window.addEventListener('hashchange', () => {
            const path = window.location.hash.slice(1) || 'login';
            this.navigate(path);
        });

        // Handle initial load
        const initialPath = window.location.hash.slice(1) || (State.isAuthenticated() ? 'dashboard' : 'login');
        this.navigate(initialPath);
    }
};
