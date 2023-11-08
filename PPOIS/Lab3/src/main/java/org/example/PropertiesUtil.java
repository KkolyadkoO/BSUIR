package org.example;

import java.io.IOException;
import java.util.Properties;


public final class PropertiesUtil {

    public static final Properties PROPERTIES = new Properties();

    static {
        loadProperties();
    }

    /**
     * constructor
     */
    private PropertiesUtil() {
    }

    /**
     *
     * @param key id key for one of the database properties
     * @return one of the database properties according to the passed key
     */
    public static String get(String key){
        return PROPERTIES.getProperty(key);
    }

    /**
     * Loads database properties from the application.properties file
     */
    private static void loadProperties() {
        try (var inputStream = PropertiesUtil.class.getClassLoader().getResourceAsStream("application.properties")) {
            PROPERTIES.load(inputStream);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
