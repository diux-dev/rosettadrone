package sq.rogue.rosettadrone.settings.drone;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.v7.preference.EditTextPreference;
import android.support.v7.preference.ListPreference;
import android.support.v7.preference.Preference;
import android.support.v7.preference.PreferenceFragmentCompat;

import java.util.Map;

import sq.rogue.rosettadrone.MainActivity;
import sq.rogue.rosettadrone.NotificationHandler;
import sq.rogue.rosettadrone.R;

import static sq.rogue.rosettadrone.util.TYPE_DRONE_ID;
import static sq.rogue.rosettadrone.util.TYPE_DRONE_RTL_ALTITUDE;

public class DroneSettingsFragment extends PreferenceFragmentCompat implements SharedPreferences.OnSharedPreferenceChangeListener {
    private static final String TAG = DroneSettingsFragment.class.getSimpleName();
    private static final String PAGE_ID = "drone_config";

    SharedPreferences sharedPreferences;

    public static DroneSettingsFragment newInstance(String pageID) {
        DroneSettingsFragment droneSettingsFragment = new DroneSettingsFragment();
        Bundle args = new Bundle();
        args.putString(PAGE_ID, pageID);
        droneSettingsFragment.setArguments(args);

        return droneSettingsFragment;
    }

    /**
     * @param savedInstanceState Any saved state we are bringing into the new fragment instance
     **/
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        sharedPreferences = getPreferenceManager().getSharedPreferences();
        getPreferenceScreen().getSharedPreferences().registerOnSharedPreferenceChangeListener(this);
        setSummaries();
    }

    /**
     *
     */
    @Override
    public void onPause() {
        sharedPreferences.unregisterOnSharedPreferenceChangeListener(this);
        super.onPause();
    }

//    /**
//     *
//     */
//    @Override
//    public void onResume() {
//        super.onResume();
//        sharedPreferences.registerOnSharedPreferenceChangeListener(this);
//
//
//        for (int i = 0; i < getPreferenceScreen().getPreferenceCount(); ++i) {
//            Preference preference = getPreferenceScreen().getPreference(i);
//            if (preference instanceof PreferenceGroup) {
//                PreferenceGroup preferenceGroup = (PreferenceGroup) preference;
//                for (int j = 0; j < preferenceGroup.getPreferenceCount(); ++j) {
//                    Preference singlePref = preferenceGroup.getPreference(j);
//                    updatePreference(singlePref);
//                }
//            } else {
//                updatePreference(preference);
//            }
//        }
//    }

    /**
     * @param savedInstanceState
     * @param rootKey
     */
    @Override
    public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
        setPreferencesFromResource(R.xml.preferences, rootKey);
        setListeners();
    }

    private void setSummaries() {
        Map<String, ?> keys = sharedPreferences.getAll();

        for (Map.Entry<String, ?> entry : keys.entrySet()) {
            updatePreference(findPreference(entry.getKey()));
        }
    }

    private void setListeners() {
        findPreference("pref_drone_id").setOnPreferenceChangeListener(new Preference.OnPreferenceChangeListener() {
            @Override
            public boolean onPreferenceChange(Preference preference, Object newValue) {

                try {
                    if (Integer.parseInt((String) newValue) >= 1 && Integer.parseInt((String) newValue) <= 254) {
                        MainActivity.FLAG_PREFS_CHANGED = true;
                        return true;
                    }
                } catch (NumberFormatException ignored) {
                }
                NotificationHandler.notifyAlert(DroneSettingsFragment.this.getActivity(), TYPE_DRONE_ID,
                        null, null);
                return false;
            }
        });
        findPreference("pref_drone_rtl_altitude").setOnPreferenceChangeListener(new Preference.OnPreferenceChangeListener() {
            @Override
            public boolean onPreferenceChange(Preference preference, Object newValue) {

                try {
                    if (Integer.parseInt((String) newValue) >= 20 && Integer.parseInt((String) newValue) <= 500) {
                        MainActivity.FLAG_PREFS_CHANGED = true;
                        return true;
                    }
                } catch (NumberFormatException ignored) {
                }
                NotificationHandler.notifyAlert(DroneSettingsFragment.this.getActivity(), TYPE_DRONE_RTL_ALTITUDE,
                        null, null);
                return false;
            }
        });
    }

    /**
     * //     * @param sharedPreferences
     * //     * @param key
     * //
     */
    @Override
    public void onSharedPreferenceChanged(SharedPreferences sharedPreferences, String key) {
        updatePreference(findPreference(key));
    }

    /**
     * @param preference
     */
    private void updatePreference(Preference preference) {
        if (preference == null) return;
        if (preference instanceof EditTextPreference) {
            EditTextPreference editTextPref = (EditTextPreference) preference;
            preference.setSummary(editTextPref.getText());
        } else if (preference instanceof ListPreference) {
            ListPreference listPreference = (ListPreference) preference;
            listPreference.setSummary(listPreference.getEntry());
            return;
        } else {
            return;
        }
        SharedPreferences sharedPrefs = getPreferenceManager().getSharedPreferences();
        preference.setSummary(sharedPrefs.getString(preference.getKey(), "Default"));
    }
}
